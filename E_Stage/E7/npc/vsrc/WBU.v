module WBU #(PC_WIDTH = 32, DATA_WIDTH = 32) (
    input  [PC_WIDTH   - 1:0] PC,
    input  [DATA_WIDTH - 1:0] jumpAddr,
    input  [DATA_WIDTH - 1:0] exu_wdata,
    input  [DATA_WIDTH - 1:0] lsu_rdata,
    input                     is_jalr,
    input                     is_lw,
    input                     is_lbu,
    output [PC_WIDTH   - 1:0] nextPC,
    output [DATA_WIDTH - 1:0] rf_wdata
);

    assign rf_wdata = (is_lw | is_lbu) ? lsu_rdata : exu_wdata;
    assign nextPC = is_jalr ? jumpAddr : (PC + 32'd4); 

endmodule
