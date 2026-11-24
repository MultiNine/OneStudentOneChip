module ysyx_27000000_IFU #(parameter [31:0] RESET_PC = 32'h3000_0000) (
    input             clock,
    input             reset,
    input      [31:0] PCin,
    input             is_mem,
    input             lsu_respValid,    // 访存指令访存完成
    input             ifu_respValid,    // 收到来自存储器的有效指令数据

    output     [31:0] ifu_raddr,        // IFU发出访存请求，向存储器提供的取指地址
    output reg [31:0] PCout,
    output            instr_valid,      // 当前取回的指令有效，开始处理
    output            instr_finish,     // 当前指令将在本周期结束时完成
    output            ifu_reqValid,     // 需要访存取指
    output            wait_lsu          // 正在执行访存指令
);
    localparam  IDLE     = 2'b00,   // 发出取指请求
                WAIT_IFU = 2'b01,   // 等待指令执行完毕
                WAIT_LSU = 2'b10;   // 访存时暂存指令
    reg [1:0] state, next_state;
    assign wait_lsu = (state == WAIT_LSU);

    always @(posedge clock) begin
        if (reset) begin
            state <= IDLE;
        end
        else begin
            state <= next_state;
        end
    end

    always @(*) begin
        case (state)
            IDLE:     next_state = WAIT_IFU;
            WAIT_IFU: next_state = ifu_respValid ? (is_mem ? WAIT_LSU : IDLE) : WAIT_IFU;
            WAIT_LSU: next_state = lsu_respValid ? IDLE : WAIT_LSU;
            default:  next_state = IDLE;
        endcase
    end

    assign ifu_raddr    = PCout;
    assign instr_valid  = !reset && (state == WAIT_IFU) && ifu_respValid;
    assign instr_finish = !reset && 
                          ( ((state == WAIT_IFU) && ifu_respValid && !is_mem) ||
                            ((state == WAIT_LSU) && lsu_respValid) );
    assign ifu_reqValid = !reset && (state == IDLE);

    always @(posedge clock) begin
        if (reset) begin
            PCout <= RESET_PC;
        end else if (instr_finish) begin
            PCout <= PCin;
        end
    end
endmodule
