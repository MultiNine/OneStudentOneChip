module GPR(
    input  wire       clk,
    input  wire       rst,
    input  wire       wen,
    input  wire [1:0] waddr,
    input  wire [7:0] wdata,
    input  wire [1:0] raddr1,
    input  wire [1:0] raddr2,
    output reg  [7:0] rdata1,
    output reg  [7:0] rdata2
);

    reg [7:0] gpr[3:0];

    assign rdata1 = gpr[raddr1];
    assign rdata2 = gpr[raddr2];

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            gpr[0] <= 8'b0;
            gpr[1] <= 8'b0;
            gpr[2] <= 8'b0;
            gpr[3] <= 8'b0;
        end
        else begin
            if (wen) begin
                gpr[waddr] <= wdata;
            end
        end
    end

endmodule
