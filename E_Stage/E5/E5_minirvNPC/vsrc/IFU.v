module IFU #(PC_WIDTH = 32, INSTR_WIDTH = 32) (
    input                          clk,
    input                          rst,
    input      [PC_WIDTH    - 1:0] PCin,
    output reg [PC_WIDTH    - 1:0] PCout,
    output     [INSTR_WIDTH - 1:0] instr
);
    import "DPI-C" function int pmem_read(input int raddr);

    always @(posedge clk) begin
        if (rst) begin
            PCout <= 32'h8000_0000;
        end 
        else begin
            PCout <= PCin;
        end
    end

    assign instr = rst ? 32'h00000013 : pmem_read(PCout);   // PC 复位时输出NOP指令

endmodule
