module top_module(
    input clk,
    input in,
    input reset,    // Synchronous reset
    output reg [7:0] out_byte,
    output reg done
); //

    // Modify FSM and datapath from Fsm_serialdata
    parameter IDLE=0, DATA=1, STOP=2, ERROR=3;
    reg [1:0] state, next_state;
    reg [3:0] count;

    wire odd;
    wire parity_rst;
    reg odd_result;

    /* 使用组合逻辑确定奇偶校验器的复位信号：
       DATA且count=0~8时奇偶校验器累计8位数据 + 1位奇偶校验位
       count=9时当前输入是停止位，不计入奇偶校验，复位奇偶校验器 */
    assign parity_rst = reset || (state != DATA) || (count == 4'd9);

    parity u_parity(
        .clk    (clk        ),
        .reset  (parity_rst ),
        .in     (in         ),
        .odd    (odd        )
    );

    always @(*) begin
        case (state)
            IDLE: begin
                if (~in)
                    next_state = DATA;
                else
                    next_state = IDLE;
            end

            DATA: begin         // count=0~8为接收的8位数据和奇偶校验位，count=9时检验是否收到停止位
                if (count == 4'd9) begin
                    if (in)
                        next_state = STOP;
                    else
                        next_state = ERROR;
                end
                else begin
                    next_state = DATA;
                end
            end

            STOP: begin
                if (~in) begin  // 接收完成后马上开始接收下一字节数据
                    next_state = DATA;
                end
                else begin
                    next_state = IDLE;
                end
            end

            ERROR: begin
                if (in == 1'b1)
                    next_state = IDLE;
                else
                    next_state = ERROR;
            end

            default: begin
                next_state = IDLE;
            end
        endcase
    end

    always @(posedge clk) begin
        if (reset) begin
            state      <= IDLE;
            count      <= 4'd0;
            odd_result <= 1'b0;
            out_byte   <= 8'd0;
        end
        else begin
            state <= next_state;

            if (state == DATA) begin
                count <= count + 4'd1;

                // New: Datapath to latch input bits.
                if (count < 4'd8)
                    out_byte[count] <= in;

                // count=9时当前输入是停止位。此时odd已经包含前面8位数据和1位校验位
                if (count == 4'd9)
                    odd_result <= odd;  // 非阻塞赋值，锁存的是时钟上升沿之前的旧odd值
            end
            else begin
                count <= 4'd0;
            end
        end
    end

    // New: Add parity checking.
    always @(*) begin
        done = (state == STOP) && odd_result;
    end

endmodule


module parity (
    input clk,
    input reset,
    input in,
    output reg odd
);

    always @(posedge clk)
        if (reset)
            odd <= 1'b0;
        else if (in)
            odd <= ~odd;

endmodule