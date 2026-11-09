module PC(
    input  wire       clk,
    input  wire       rst,
    input  wire [7:0] PCin,
    output reg  [7:0] PCout
);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            PCout <= 8'b0;
        end 
        else begin
            PCout <= PCin;    
        end
    end

endmodule
