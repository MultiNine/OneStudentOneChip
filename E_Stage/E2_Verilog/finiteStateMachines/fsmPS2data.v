module top_module(
    input clk,
    input [7:0] in,
    input reset,    // Synchronous reset
    output reg [23:0] out_bytes,
    output done); 

    // State transition logic (combinational)
    parameter IDLE=0, BYTE1=1, BYTE2=2, FINISH=3;
    reg [1:0] state, next_state;

    always @(*) begin
        case (state)
            IDLE: begin
                if (in[3]) begin
                    next_state = BYTE1;
                end
                else begin
                    next_state = IDLE;
                end
            end
            BYTE1: begin            // 此时已有1个有效字节
                next_state = BYTE2;
            end
            BYTE2: begin
                next_state = FINISH;
            end
            FINISH: begin
                if (in[3]) begin
                    next_state = BYTE1;
                end
                else begin
                    next_state = IDLE;
                end
            end
        endcase
    end

    // State flip-flops (sequential)
    always @(posedge clk) begin
        if (reset) begin
            state <= IDLE;
        end
        else begin
            state <= next_state;
            case (state)
                IDLE:
                    if (in[3])
                        out_bytes[23:16] <= in;

                BYTE1:
                    out_bytes[15:8] <= in;

                BYTE2:
                    out_bytes[7:0] <= in;

                FINISH:
                    if (in[3])
                        out_bytes[23:16] <= in;
            endcase
        end
    end
 
    // Output logic
    assign done = (state == FINISH);

endmodule
