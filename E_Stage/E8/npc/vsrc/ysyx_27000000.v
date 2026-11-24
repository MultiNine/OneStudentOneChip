module ysyx_27000000 #(parameter [31:0] RESET_PC = 32'h3000_0000) (
    input          clock,
    input          reset,

    // Instruction memory
    input  [31:0] io_ifu_rdata,     // 从存储器读出的指令
    input         io_ifu_respValid, // 存储器取指完成
    input         io_lsu_respValid, // 存储器访存完成
    output [31:0] io_ifu_addr,      // IFU发出访存请求，向存储器提供的取指地址
    output        io_ifu_reqValid,  // 告知存储器可以取指
    output        io_lsu_reqValid,  // 告知存储器可以访存

    // Data memory
    input  [31:0] io_lsu_rdata,
    output [31:0] io_lsu_addr,
    output [ 1:0] io_lsu_size,    
    output [31:0] io_lsu_wdata,
    output [ 3:0] io_lsu_wmask,
    output        io_lsu_wen         // 面向top存储器的写使能
);

    wire [31:0] PCin;
    wire [31:0] PCout               /* verilator public_flat_rd */;
    wire        instr_valid;        // 当前取回的指令有效，开始处理
    wire        instr_finish        /* verilator public_flat_rd */;      
    wire        is_jalr, is_add, is_lui,
                is_lw, is_sw, is_lbu, is_sb, is_csrrs;
    wire [31:0] imm_I, imm_S, imm_U;
    wire [31:0] jumpAddr;
    wire [11:0] csr_addr;
    wire        is_ebreak           /* verilator public_flat_rd */;
    wire        is_ebreak_idu;
    wire [31:0] a0                  /* verilator public_flat_rd */;         
    assign is_ebreak = is_ebreak_idu && instr_valid;

    wire [ 4:0] waddr;
    wire [31:0] wdata;
    wire [ 4:0] raddr1;
    wire [ 4:0] raddr2;
    wire [31:0] rdata1;
    wire [31:0] rdata2;

    wire        idu_wen;    // 当前指令是否需要写GPR
    wire [31:0] exu_wdata;
    wire [31:0] lsu_loaddata;

    wire [31:0] normal_wdata;
    wire [4:0]  rf_waddr;
    wire        rf_wen;

    wire        is_mem = is_lw | is_lbu | is_sw | is_sb;
    wire        wait_lsu;
    reg  [4:0]  mem_rd;
    reg  [1:0]  mem_offset;
    reg         mem_is_load;
    reg         mem_is_lbu;

    assign wdata = wait_lsu ? lsu_loaddata : normal_wdata;
    assign rf_waddr = wait_lsu ? mem_rd : waddr;
    assign rf_wen = instr_finish && (wait_lsu ? mem_is_load : idu_wen);

    // 发出访存请求时保存当前所需的信息
    always @(posedge clock) begin
        if (io_lsu_reqValid) begin
            mem_rd      <= waddr;
            mem_offset  <= io_lsu_addr[1:0];
            mem_is_load <= is_lw | is_lbu;
            mem_is_lbu  <= is_lbu;
        end
    end

    reg [63:0] mcycle_cnt;
    always @(posedge clock) begin
        if (reset) begin
            mcycle_cnt <= 64'd0;
        end
        else begin
            mcycle_cnt <= mcycle_cnt + 64'd1;
        end
    end      

    ysyx_27000000_IFU #(.RESET_PC(RESET_PC)) u_IFU (
        .clock(clock),
        .reset(reset),
        .PCin(PCin),
        .is_mem(is_mem),
        .lsu_respValid(io_lsu_respValid),
        .ifu_respValid(io_ifu_respValid),

        .ifu_raddr(io_ifu_addr),
        .PCout(PCout),
        .instr_valid(instr_valid),
        .instr_finish(instr_finish),
        .ifu_reqValid(io_ifu_reqValid),
        .wait_lsu(wait_lsu)
    );

    ysyx_27000000_IDU u_IDU (
        .instr(io_ifu_rdata),

        .idu_wen(idu_wen),
        .rd(waddr),
        .rs1(raddr1),
        .rs2(raddr2),
        .is_jalr(is_jalr),
        .is_add(is_add),
        .is_lui(is_lui),
        .is_lw(is_lw),
        .is_sw(is_sw),
        .is_lbu(is_lbu),
        .is_sb(is_sb),
        .is_ebreak(is_ebreak_idu),
        .is_csrrs(is_csrrs),
        .immOut_I(imm_I),
        .immOut_S(imm_S),
        .immOut_U(imm_U),
        .csr_addr(csr_addr)
    );

    ysyx_27000000_RegisterFile u_RegisterFile (
        .clock(clock),
        .wdata(wdata),
        .waddr(rf_waddr),
        .wen(rf_wen),
        .raddr1(raddr1),
        .raddr2(raddr2),

        .rdata1(rdata1),
        .rdata2(rdata2),
        .a0(a0)
    );

    ysyx_27000000_EXU u_EXU (
        .PC(PCout),
        .is_jalr(is_jalr),
        .is_add(is_add),
        .is_lui(is_lui),
        .is_sw(is_sw),
        .is_sb(is_sb),
        .rdata1(rdata1),
        .rdata2(rdata2),
        .imm_I(imm_I),
        .imm_S(imm_S),
        .imm_U(imm_U),

        .exu_wdata(exu_wdata),
        .jumpAddr(jumpAddr),
        .memAddr(io_lsu_addr)
    );

    ysyx_27000000_WBU u_WBU (
        .PC(PCout),
        .jumpAddr(jumpAddr),
        .exu_wdata(exu_wdata),
        .is_jalr(is_jalr && instr_valid),
        .is_csrrs(is_csrrs),
        .csr_addr(csr_addr),
        .mcycle_cnt(mcycle_cnt),
        
        .nextPC(PCin),
        .rf_wdata(normal_wdata)
    );

    ysyx_27000000_LSU u_LSU (
        .is_lw(is_lw),
        .is_sw(is_sw),
        .is_lbu(is_lbu),
        .is_sb(is_sb),
        .mem_is_load(mem_is_load),
        .mem_is_lbu(mem_is_lbu),
        .mem_offset(mem_offset),
        .rdata2(rdata2),
        .instr_valid(instr_valid),
        .lsu_offst(io_lsu_addr[1:0]),
        .lsu_rdata(io_lsu_rdata),
        .lsu_respValid(io_lsu_respValid),

        .lsu_size(io_lsu_size),
        .lsu_wen(io_lsu_wen),
        .lsu_wdata(io_lsu_wdata),
        .lsu_wmask(io_lsu_wmask),
        .lsu_loaddata(lsu_loaddata),
        .lsu_reqValid(io_lsu_reqValid)
    );
endmodule
