module top #(PC_WIDTH = 32,
             INSTR_WIDTH = 32,
             ADDR_WIDTH  = 4, 
             DATA_WIDTH = 32
             ) (
    input                      clk,
    input                      rst,
    output [   PC_WIDTH - 1:0] PC,
    output [INSTR_WIDTH - 1:0] instr
);
    import "DPI-C" function void NPC_ebreak(input int a0);
    import "DPI-C" function int pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);

    wire  [ DATA_WIDTH - 1:0] mem_addr;
    wire                      mem_ren;
    wire                      mem_wen;
    wire  [ DATA_WIDTH - 1:0] mem_rdata;
    wire  [ DATA_WIDTH - 1:0] mem_wdata;
    wire  [              7:0] mem_wmask;
    wire                      is_ebreak;
    wire  [ DATA_WIDTH - 1:0] a0;

    assign instr = rst ? 32'h00000013 : pmem_read(PC);
    assign mem_rdata = (!rst && mem_ren) ? pmem_read(mem_addr) : 32'b0;

    always @(posedge clk) begin
        if (!rst && is_ebreak) begin
            NPC_ebreak(a0);
        end
    end

    always @(*) begin
        if (mem_wen) begin
            pmem_write(mem_addr, mem_wdata, mem_wmask);
        end
    end

    NPC #(
    .PC_WIDTH(PC_WIDTH),
    .INSTR_WIDTH(INSTR_WIDTH),
    .ADDR_WIDTH(ADDR_WIDTH),
    .DATA_WIDTH(DATA_WIDTH)
    ) u_NPC (
        .clk(clk),
        .rst(rst),
        .PC(PC),
        .instr(instr),

        .memAddr(mem_addr),
        .dataFromMem(mem_rdata),
        .mem_ren(mem_ren),
        .mem_wen(mem_wen),
        .mem_wdata(mem_wdata),
        .mem_wmask(mem_wmask),

        .is_ebreak(is_ebreak),
        .a0(a0)
    );
endmodule
