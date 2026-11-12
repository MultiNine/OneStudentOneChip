module IFU #(PC_WIDTH = 32, INSTR_WIDTH = 32) (
    input                          clk,
    input      [PC_WIDTH    - 1:0] PCin,
    output reg [PC_WIDTH    - 1:0] PCout,
    output     [INSTR_WIDTH - 1:0] instr
);
    import "DPI-C" function int pmem_read(input int raddr);

    always @(posedge clk) begin
        PCout <= PCin;
    end

    assign instr = pmem_read(PCout);

endmodule
