module top_module (
    input clk,
    input reset,
    input [31:0] in,
    output reg [31:0] out
);

    reg [31:0] in_prev;

    always @(posedge clk) begin
        in_prev <= in;
        if (reset) begin
            out <= 32'b0;
        end
        else begin
            out <= (in_prev & ~in) | out;
        end
    end

endmodule
