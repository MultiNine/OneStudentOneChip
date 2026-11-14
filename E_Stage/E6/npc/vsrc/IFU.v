module IFU #(PC_WIDTH = 32) (
    input                          clk,
    input                          rst,
    input      [PC_WIDTH    - 1:0] PCin,
    output reg [PC_WIDTH    - 1:0] PCout
);

    always @(posedge clk) begin
        if (rst) begin
            PCout <= 32'h8000_0000;
        end 
        else begin
            PCout <= PCin;
        end
    end

endmodule
