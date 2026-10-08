module top_module(
    input clk,
    input load,
    input [511:0] data,
    output reg [511:0] q );

    wire [511:0] Left;
    wire [511:0] Right;
    assign Left  = {1'b0, q[511:1]};
    assign Right = {q[510:0], 1'b0};

    always @(posedge clk) begin
        if (load) begin
            q <= data;
        end
        else begin
            q <= (q ^ Right) | (~Left & q & Right);
        end
    end 

endmodule
