module sCPU(
    input  wire       clk, 
    input  wire       rst,
    input  wire [7:0] datain,
    output reg  [7:0] out_led,
    output wire [7:0] segh0,
    output wire [7:0] segh1   );

    wire [7:0] PCin;
    wire [7:0] PCout;
    wire [7:0] ins;
    wire ins_add, ins_li, ins_io, ins_bner0;
    wire       wen;
    wire [1:0] waddr;
    wire [7:0] wdata;
    wire [1:0] raddr1, raddr2;
    reg  [7:0] rdata1, rdata2;
    reg  [7:0] out_seg;

    wire [7:0] PCadd;
    assign PCin  = PCout + PCadd;
    assign PCadd = (ins_bner0 & (rdata1 != rdata2)) ? 
                    {{4{ins[5]}}, ins[5:2]} : 8'b1;

    reg  [7:0] offset;
    wire [1:0] s   = ins[3:2];
    wire [1:0] imm = ins[1:0];
    always @(*) begin
        case (s)
            2'b00:   offset = {6'b0, imm};
            2'b01:   offset = {4'b0, imm, 2'b0};
            2'b10:   offset = {2'b0, imm, 4'b0};
            2'b11:   offset = {imm, 6'b0};
            default: offset = 8'b0;
        endcase
    end
    assign wen    = ins_add | ins_li | (ins_io & ~ins[3]);
    assign waddr  = ins[5:4];
    assign wdata  = (ins_io & ~ins[3]) ? datain : 
                    (ins_add ? (rdata1 + rdata2) : offset);
    assign raddr1 = ins_bner0 ? 2'b0     : ins[3:2];
    assign raddr2 = ins_io    ? ins[5:4] : ins[1:0];

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            out_led <= 8'b0;
            out_seg <= 8'b0;
        end
        else begin
            if (ins_io & ins[3] & ~ins[0]) begin
                out_led <= rdata2;
            end
            if (ins_io & ins[3] & ins[0]) begin
                out_seg <= rdata2;
            end
        end
    end

    PC u_PC (
        .clk(clk),
        .rst(rst),
        .PCin(PCin),
        .PCout(PCout)
    );

    insROM u_insROM (
        .addr(PCout),
        .ins(ins)
    );

    ID u_ID (
        .ins(ins),
        .ins_add(ins_add),
        .ins_io(ins_io),
        .ins_li(ins_li),
        .ins_bner0(ins_bner0)
    );
    
    GPR u_GPR (
        .clk(clk),
        .rst(rst),
        .wen(wen),
        .waddr(waddr),
        .wdata(wdata),
        .raddr1(raddr1),
        .raddr2(raddr2),
        .rdata1(rdata1),
        .rdata2(rdata2)
    );

    bcd7seg seg0 (.b(out_seg[3:0]), .h(segh0));
    bcd7seg seg1 (.b(out_seg[7:4]), .h(segh1));

endmodule
