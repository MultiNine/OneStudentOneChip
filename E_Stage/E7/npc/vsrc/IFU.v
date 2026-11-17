module IFU #(PC_WIDTH = 32, DATA_WIDTH = 32) (
    input                         clk,
    input                         rst,
    input      [PC_WIDTH   - 1:0] PCin,
    input                         is_mem,
    input                         lsu_respValid,// 访存指令访存完成
    input                         ifu_respValid,// 收到来自存储器的有效指令数据
    output     [DATA_WIDTH - 1:0] ifu_raddr,    // IFU发出访存请求，向存储器提供的取指地址
    output reg [PC_WIDTH   - 1:0] PCout,
    output                        instr_valid,  // 当前取回的指令有效，开始处理
    output                        instr_finish, // 当前指令将在本周期结束时完成
    output                        ifu_reqValid  // 需要访存取指
);

    parameter   IDLE = 1'b0,  // 发出取指请求
                WAIT = 1'b1;  // 等待指令执行完毕
    reg state, next_state;

    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
        end
        else begin
            state <= next_state;
        end
    end

    always @(*) begin
        case (state)
            IDLE:    next_state = WAIT;
            WAIT:    next_state = instr_finish ? IDLE : WAIT;
            default: next_state = IDLE;
        endcase
    end

    assign ifu_raddr    = PCout;
    assign instr_valid  = !rst && (state == WAIT) && ifu_respValid;
    assign instr_finish = !rst && (state == WAIT) && 
                          ( (!is_mem && ifu_respValid) || (is_mem && lsu_respValid) ) ;
    assign ifu_reqValid = !rst && (state == IDLE);

    always @(posedge clk) begin
        if (rst) begin
            PCout <= 32'h8000_0000;
        end 
        else if (instr_finish) begin
            PCout <= PCin;
        end
    end

endmodule