module top_module (
    input clk,
    input aresetn,    // Asynchronous active-low reset
    input x,
    output reg z );

    parameter S0=0, S1=1, S2=2;
    reg [1:0] state, next_state;

    always @(*) begin
        case (state)
            S0: begin
                next_state = (x == 1'b0) ? S0 : S1;
                z = 1'b0;
            end
            S1: begin
                next_state = (x == 1'b0) ? S2 : S1;
                z = 1'b0;
            end
            S2: begin
                next_state = (x == 1'b0) ? S0 : S1;
                z = (x == 1'b0) ? 1'b0 : 1'b1;
            end
        endcase
    end

    always @(posedge clk or negedge aresetn) begin
        if (~aresetn) begin
            state <= S0;
        end
        else begin
            state <= next_state;
        end
    end

endmodule
