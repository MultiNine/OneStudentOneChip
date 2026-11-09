module ID(
    input  wire [7:0] ins,
    output wire       ins_add,
    output wire       ins_io,
    output wire       ins_li,
    output wire       ins_bner0
);
    assign ins_add   = (ins[7:6] == 2'b00) ? 1'b1 : 1'b0;
    assign ins_io    = (ins[7:6] == 2'b01) ? 1'b1 : 1'b0;
    assign ins_li    = (ins[7:6] == 2'b10) ? 1'b1 : 1'b0;
    assign ins_bner0 = (ins[7:6] == 2'b11) ? 1'b1 : 1'b0;

endmodule
