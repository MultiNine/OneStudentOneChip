module top_module(
    input clk,
    input in,
    input reset,    // Synchronous reset
    output reg[7:0] out_byte,
    output reg done
); //

    // Use FSM from Fsm_serial
    parameter IDLE=0, DATA=1, STOP=2, ERROR=3;
    reg [1:0] state, next_state;
    reg [3:0] count = 4'd0;

    always @(*) begin
        case (state)
            IDLE: begin
                if (~in)
                    next_state = DATA;
                else
                    next_state = IDLE;
            end
            DATA: begin
                if (count == 4'd8) begin    // count0~7为接收的8位数据，count为9时检验是否收到停止位
                    if (in) begin
                        next_state = STOP;
                    end
                    else begin
                        next_state = ERROR;
                    end  
                end
                else begin
                    next_state = DATA;
                end
            end
            STOP: begin
                if (~in) begin              // 接收完成后马上开始接收下一字节数据
                    next_state = DATA;
                end
                else begin
                    next_state = IDLE;
                end
            end
            ERROR: begin
                if (in == 1'b1) begin
                    next_state = IDLE;
                end
                else begin
                    next_state = ERROR;
                end
            end
        endcase
    end

    always @(posedge clk) begin
        if (reset) begin
            state <= IDLE;
            count <= 4'd0;
        end
        else begin
            state <= next_state;

            if (state == DATA) begin
                count <= count + 4'd1;
            end
            else begin
                count <= 4'd0;
            end
        end
    end

    always @(*) begin
        done = (state == STOP); 
    end

    // New: Datapath to latch input bits.
    always @(posedge clk) begin
        if (state == DATA && count < 4'd8) begin
            out_byte[count] <= in; 
        end
    end

endmodule
