module scancode2ascii(scancode, key_valid, ascii);
    input  [7:0] scancode;
    output       key_valid;
    output [7:0] ascii;

    assign key_valid = (ascii != 8'b0000_0000); 

    MuxKeyWithDefault #(36, 8, 8) scancode2asciiMux (
        .out(ascii),
        .key(scancode),
        .default_out(8'b0000_0000),
        .lut( {
                // A-Z (scancode, lowercase ASCII)
                8'h1C, 8'h61,   // A
                8'h32, 8'h62,   // B
                8'h21, 8'h63,   // C
                8'h23, 8'h64,   // D
                8'h24, 8'h65,   // E
                8'h2B, 8'h66,   // F
                8'h34, 8'h67,   // G
                8'h33, 8'h68,   // H
                8'h43, 8'h69,   // I
                8'h3B, 8'h6A,   // J
                8'h42, 8'h6B,   // K
                8'h4B, 8'h6C,   // L
                8'h3A, 8'h6D,   // M
                8'h31, 8'h6E,   // N
                8'h44, 8'h6F,   // O
                8'h4D, 8'h70,   // P
                8'h15, 8'h71,   // Q
                8'h2D, 8'h72,   // R
                8'h1B, 8'h73,   // S
                8'h2C, 8'h74,   // T
                8'h3C, 8'h75,   // U
                8'h2A, 8'h76,   // V
                8'h1D, 8'h77,   // W
                8'h22, 8'h78,   // X
                8'h35, 8'h79,   // Y
                8'h1A, 8'h7A,   // Z

                // 0-9
                8'h45, 8'h30,   // 0
                8'h16, 8'h31,   // 1
                8'h1E, 8'h32,   // 2
                8'h26, 8'h33,   // 3
                8'h25, 8'h34,   // 4
                8'h2E, 8'h35,   // 5
                8'h36, 8'h36,   // 6
                8'h3D, 8'h37,   // 7
                8'h3E, 8'h38,   // 8
                8'h46, 8'h39    // 9
        } )
    );

endmodule
