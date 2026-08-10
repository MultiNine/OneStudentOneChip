module top_module (
    input clk,
    input areset,
    input x,
    output reg z
);

    // state[0] for state A, state[1] for state B
    reg [1:0] state, next_state;

    always @(*) begin
        if (state[0]) begin
            next_state = (x == 1'b0) ? 2'b01 : 2'b10;
            z = (x == 1'b0) ? 1'b0 : 1'b1;
        end
        else begin
            next_state = 2'b10;
            z = (x == 1'b0) ? 1'b1 : 1'b0;
        end
    end

    always @(posedge clk or posedge areset) begin
        if (areset) begin
            state <= 2'b01;
        end
        else begin
            state <= next_state;
        end
    end

endmodule
