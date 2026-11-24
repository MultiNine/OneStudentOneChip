module ysyx_27000000_WBU (
    input  [31:0] PC,
    input  [31:0] jumpAddr,
    input  [31:0] exu_wdata,
    input         is_jalr,
    input         is_csrrs,
    input  [11:0] csr_addr,
    input  [63:0] mcycle_cnt,
    output [31:0] nextPC,
    output [31:0] rf_wdata
);
    wire [31:0] csr_data;
    assign csr_data = (csr_addr == 12'hf11) ? 32'h79737978 :
                      (csr_addr == 12'hf12) ? 32'h05F63B08 :
                      (csr_addr == 12'hb00) ? mcycle_cnt[31:0] :
                      (csr_addr == 12'hb80) ? mcycle_cnt[63:32] : 32'h0;

    assign rf_wdata = is_csrrs ? csr_data : exu_wdata;
    assign nextPC = is_jalr ? jumpAddr : (PC + 32'd4); 
endmodule
