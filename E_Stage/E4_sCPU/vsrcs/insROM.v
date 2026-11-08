module insROM(
    input  wire [7:0] addr,
    output reg  [7:0] ins
);
    localparam ins0  = 8'h86;
    localparam ins1  = 8'h92;
    localparam ins2  = 8'h01;
    localparam ins3  = 8'h90;
    localparam ins4  = 8'ha0;
    localparam ins5  = 8'hb1;
    localparam ins6  = 8'h17;
    localparam ins7  = 8'h29;
    localparam ins8  = 8'hf9;
    localparam ins9  = 8'h68;
    localparam ins10 = 8'h69;
    localparam ins11 = 8'hc3;
    localparam ins12 = 8'h00;
    localparam ins13 = 8'h00;
    localparam ins14 = 8'h00;
    localparam ins15 = 8'h00;

    always @(*) begin
        case (addr[3:0])
            4'd0:    ins = ins0;
            4'd1:    ins = ins1;
            4'd2:    ins = ins2;
            4'd3:    ins = ins3;
            4'd4:    ins = ins4;
            4'd5:    ins = ins5;
            4'd6:    ins = ins6;
            4'd7:    ins = ins7;
            4'd8:    ins = ins8;
            4'd9:    ins = ins9;
            4'd10:   ins = ins10;
            4'd11:   ins = ins11;
            4'd12:   ins = ins12;
            4'd13:   ins = ins13;
            4'd14:   ins = ins14;
            4'd15:   ins = ins15;
            default: ins = ins0;
        endcase
    end

endmodule
