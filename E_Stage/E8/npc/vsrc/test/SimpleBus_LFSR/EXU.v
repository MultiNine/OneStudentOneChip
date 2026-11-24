module EXU #(DATA_WIDTH = 32) (
    input  [DATA_WIDTH - 1:0] PC,
    input                     is_jalr,
    input                     is_add,
    input                     is_lui,
    input                     is_sw,
    input                     is_sb,
    input  [DATA_WIDTH - 1:0] rdata1,
    input  [DATA_WIDTH - 1:0] rdata2,
    input  [DATA_WIDTH - 1:0] imm_I,
    input  [DATA_WIDTH - 1:0] imm_S,
    input  [DATA_WIDTH - 1:0] imm_U,
    output [DATA_WIDTH - 1:0] wdata,
    output [DATA_WIDTH - 1:0] jumpAddr,
    output [DATA_WIDTH - 1:0] memAddr
);
    wire [DATA_WIDTH - 1:0] addResult;
    wire [DATA_WIDTH - 1:0] addOP2;
    
    assign addOP2    = is_add ? rdata2 :
                       (is_sw | is_sb) ? imm_S : imm_I;
    assign addResult = rdata1 + addOP2;

    assign jumpAddr  = {addResult[31:1], 1'b0};
    assign wdata = is_lui  ? imm_U :
                   is_jalr ? (PC + 32'd4) : addResult;
    assign memAddr = addResult;

endmodule
