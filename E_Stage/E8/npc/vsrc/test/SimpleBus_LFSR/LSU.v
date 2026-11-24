module LSU #(DATA_WIDTH = 32) (
    input                         clk,
    input                         rst,
    input                         is_lw,
    input                         is_sw,
    input                         is_lbu,
    input                         is_sb,
    input      [DATA_WIDTH - 1:0] rdata2,       // 来自GPR的rdata2 供sw/sb写入存储器
    input                         instr_valid,  // 当前取回的指令有效，开始处理
    input      [DATA_WIDTH - 1:0] lsu_addr,     // 同时作为读地址和写地址
    input      [DATA_WIDTH - 1:0] lsu_rdata,    // 通过DPI-C从存储器读回的数据
    input                         lsu_respValid,// 存储器返回有效数据
    
    output                        lsu_wen,      // 1使能写 0使能读
    output     [DATA_WIDTH - 1:0] lsu_wdata,    // 写入存储器的数据
    output reg [             3:0] lsu_wmask,
    output reg [DATA_WIDTH - 1:0] lsu_loaddata, // 经LSU处理后供lw/lbu使用的读数据
    output                        lsu_reqValid  // 需要访存

);
    reg [7:0] lsu_lfsr;
    wire feedback = lsu_lfsr[4] ^ lsu_lfsr[3] ^ lsu_lfsr[2] ^ lsu_lfsr[0];
    wire [5:0] lsu_delay = {1'b0, lsu_lfsr[4:0]} + 6'd1;
    reg  [5:0] lsu_delay_cnt;

    parameter IDLE = 2'b00, DELAY = 2'b01, WAIT = 2'b10;
    reg [1:0] state, next_state;

    always@(posedge clk) begin
        if(rst) begin
            lsu_lfsr <= 8'b0000_0001;
        end
        else if ((state == WAIT) && lsu_respValid) begin
            lsu_lfsr <= {feedback, lsu_lfsr[7:1]};
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            lsu_delay_cnt <= 6'd0;
        end else begin
            state <= next_state;
            if (state == IDLE) begin
                if (instr_valid && (is_lw || is_lbu || is_sw || is_sb)) begin
                    lsu_delay_cnt <= lsu_delay;
                end
            end
            if (state == DELAY) begin
                if (lsu_delay_cnt != 6'd0) begin
                    lsu_delay_cnt <= lsu_delay_cnt - 6'd1;
                end
            end
        end
    end

    always @(*) begin
        case (state)
            IDLE:    next_state = ( instr_valid && (is_lw || is_lbu || is_sw || is_sb) ) ?
                                DELAY : IDLE;
            DELAY:   next_state = (lsu_delay_cnt == 6'd0) ? WAIT : DELAY;
            WAIT:    next_state = lsu_respValid ? IDLE : WAIT;
            default: next_state = IDLE;
        endcase
    end

    assign lsu_wen = is_sw | is_sb;
    assign lsu_wdata = is_sw ? rdata2 : (rdata2 << {lsu_addr[1:0], 3'b000});
    assign lsu_reqValid = !rst && (state == DELAY) && (lsu_delay_cnt == 0); // 防止重复访存

    always @(*) begin
        if (is_sw) begin
            lsu_wmask = 4'b1111;
        end
        else if (is_sb) begin
            case (lsu_addr[1:0])
                2'b00:   lsu_wmask = 4'b0001;
                2'b01:   lsu_wmask = 4'b0010;
                2'b10:   lsu_wmask = 4'b0100;
                2'b11:   lsu_wmask = 4'b1000;
                default: lsu_wmask = 4'b0000;
            endcase
        end
        else begin
            lsu_wmask = 4'b0000;
        end
    end

    always @(*) begin
        if (is_lw && lsu_respValid) begin
            lsu_loaddata = lsu_rdata;
        end
        else if (is_lbu && lsu_respValid) begin
            case (lsu_addr[1:0])
                2'b00:   lsu_loaddata = {24'b0, lsu_rdata[7:0]};
                2'b01:   lsu_loaddata = {24'b0, lsu_rdata[15:8]};
                2'b10:   lsu_loaddata = {24'b0, lsu_rdata[23:16]};
                2'b11:   lsu_loaddata = {24'b0, lsu_rdata[31:24]};
                default: lsu_loaddata = 32'h0000_0000;
            endcase
        end 
        else begin
            lsu_loaddata = 32'h0000_0000;
        end
    end
endmodule
