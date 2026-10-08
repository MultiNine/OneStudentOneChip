module top_module (
    input clk,
    input j,
    input k,
    output reg Q);

    wire Din;
    assign Din = (j & ~k) | (~j & ~k & Q) | (j & k & ~Q);

    always @(posedge clk) begin
        Q <= Din;
    end 

endmodule
