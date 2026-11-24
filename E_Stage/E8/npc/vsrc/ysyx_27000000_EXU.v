module ysyx_27000000_EXU (
    input  [31:0] PC,
    input         is_jalr,
    input         is_add,
    input         is_lui,
    input         is_sw,
    input         is_sb,
    input  [31:0] rdata1,
    input  [31:0] rdata2,
    input  [31:0] imm_I,
    input  [31:0] imm_S,
    input  [31:0] imm_U,
    
    output [31:0] exu_wdata,
    output [31:0] jumpAddr,
    output [31:0] memAddr
);
    wire [31:0] addResult;
    wire [31:0] addOP2;
    
    assign addOP2    =  is_add ? rdata2 :
                        (is_sw | is_sb) ? imm_S : imm_I;
    assign addResult =  rdata1 + addOP2;

    assign jumpAddr  =  {addResult[31:1], 1'b0};
    assign exu_wdata =  is_lui  ? imm_U :
                        is_jalr ? (PC + 32'd4) : addResult;
    assign memAddr   =  addResult;
endmodule
