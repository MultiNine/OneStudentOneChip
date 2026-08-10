module top_module(
    input clk,
    input [7:0] in,
    input reset,    // Synchronous reset
    output done); //

    // State transition logic (combinational)
    parameter IDLE=0, BYTE1=1, BYTE2=2, FINISH=3;
    reg [1:0] state, next_state;

    always @(*) begin
        case (state)
            IDLE: begin
                next_state = (in[3] == 1'b1) ? BYTE1 : IDLE;
            end
            BYTE1: begin            // 此时已有1个有效字节
                next_state = BYTE2;
            end
            BYTE2: begin
                next_state = FINISH;
            end
            FINISH: begin
                next_state = (in[3] == 1'b1) ? BYTE1 : IDLE;
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
        end
    end
 
    // Output logic
    assign done = (state == FINISH);

endmodule
