`timescale 1ns/1ps

module ALU(A, B, aluop, out, carry, overflow, zero, segA, segB, segOut);
    input       [3:0]   A;
    input       [3:0]   B;
    input       [2:0]   aluop;
    output reg  [3:0]   out;
    output              carry;
    output              overflow;
    output              zero;
    output      [7:0]   segA;
    output      [7:0]   segB;
    output      [7:0]   segOut;

    wire ctrl;
    wire [3:0] out_addsub;
    assign ctrl = (aluop == 3'b000) ? 1'b0 : 1'b1;

    wire aless;
    assign aless = out_addsub[3] ^ overflow;

    addSub4bit u_addSub4bit (
        .a(A),
        .b(B),
        .ctrl(ctrl),
        .carry(carry),
        .zero(zero),
        .overflow(overflow),
        .result(out_addsub)
    );

    bcd7seg A_seg   (.b(A),   .h(segA));
    bcd7seg B_seg   (.b(B),   .h(segB));
    bcd7seg Out_seg (.b(out), .h(segOut));

    always @(*) begin
        case (aluop)
            3'b000:  out = out_addsub;
            3'b001:  out = out_addsub;
            3'b010:  out = ~A;
            3'b011:  out = A & B;
            3'b100:  out = A | B;
            3'b101:  out = A ^ B;
            3'b110:  out = {3'b000, aless};
            3'b111:  out = {3'b000, zero};
            default: out = 4'b0000;
        endcase
    end

endmodule
