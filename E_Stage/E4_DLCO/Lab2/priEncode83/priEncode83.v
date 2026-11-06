module priEncode83(en, x, validIn, y, segOut);
    input               en;
    input       [7:0]   x;
    output reg          validIn;
    output reg  [2:0]   y;
    output      [7:0]   segOut;

    wire [7:0] segData;
    bcd7seg u_seg (.b({1'b0, y}), .h(segData));
    assign segOut = (validIn && en) ? segData : 8'b1111_1111; 

    always @(en or x) begin
        if(en) begin
            casez (x)
                8'b0000_0001:   begin validIn = 1'b1; y = 3'b000; end
                8'b0000_001?:   begin validIn = 1'b1; y = 3'b001; end
                8'b0000_01??:   begin validIn = 1'b1; y = 3'b010; end
                8'b0000_1???:   begin validIn = 1'b1; y = 3'b011; end
                8'b0001_????:   begin validIn = 1'b1; y = 3'b100; end
                8'b001?_????:   begin validIn = 1'b1; y = 3'b101; end
                8'b01??_????:   begin validIn = 1'b1; y = 3'b110; end
                8'b1???_????:   begin validIn = 1'b1; y = 3'b111; end
                default:        begin validIn = 1'b0; y = 3'b000; end
            endcase
        end
        else begin
            casez (x)
                8'b0000_0001:   begin validIn = 1'b1; y = 3'b000; end
                8'b0000_001?:   begin validIn = 1'b1; y = 3'b000; end
                8'b0000_01??:   begin validIn = 1'b1; y = 3'b000; end
                8'b0000_1???:   begin validIn = 1'b1; y = 3'b000; end
                8'b0001_????:   begin validIn = 1'b1; y = 3'b000; end
                8'b001?_????:   begin validIn = 1'b1; y = 3'b000; end
                8'b01??_????:   begin validIn = 1'b1; y = 3'b000; end
                8'b1???_????:   begin validIn = 1'b1; y = 3'b000; end
                default:        begin validIn = 1'b0; y = 3'b000; end
            endcase
        end
    end

endmodule
