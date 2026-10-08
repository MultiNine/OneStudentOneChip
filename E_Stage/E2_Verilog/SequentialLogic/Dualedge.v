module top_module (
    input clk,
    input d,
    output reg q
);

    reg n, p;


    always @(posedge clk) begin
        p <= n ^ d; 
    end

    always @(negedge clk) begin
        n <= p ^ d;
    end

    // 上升沿时 q = n ^ p = n ^ n ^ d = 0 ^ d = d
    // 下降沿时 q = n ^ p = p ^ d ^ p = 0 ^ d = d
    always @(*) begin
        q = n ^ p;
    end

endmodule
