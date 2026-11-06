module top(
    input        clk,
    input        clrn,
    input        ps2_clk, 
    input        ps2_dat,

    output       ready,
    output       sampling,
    output       overflow,
    output [7:0] seg0_out,
    output [7:0] seg1_out,
    output [7:0] seg2_out,
    output [7:0] seg3_out,
    output [7:0] seg4,
    output [7:0] seg5 );

    wire [7:0] data;
    reg        nextdata_n;

    wire       key_valid;
    wire [7:0] ascii;

    wire [7:0] count;
    wire       is_pressed;
    wire [7:0] current_key;

    parameter IDLE = 1'b0, ACK = 1'b1;
    reg       state, next_state;
    reg [7:0] scancode;
    reg       scan_valid;

    always @(posedge clk) begin
        if (~clrn) begin
            state      <= IDLE;
            scancode   <= 8'h00;
            scan_valid <= 1'b0;
        end
        else begin
            state <= next_state;
            scan_valid <= 1'b0;
            if (state == IDLE && ready) begin
                scancode   <= data;
                scan_valid <= 1'b1;
            end
        end
    end

    always @(*) begin
        case (state)
            IDLE:    next_state = ready ? ACK : IDLE;  
            ACK:     next_state = IDLE;
            default: next_state = IDLE;
        endcase
         
    end

    always @(*) begin
        nextdata_n =  ~(state == ACK);
    end

    ps2_keyboard u_ps2_keyboard (
        .clk(clk),
        .clrn(clrn),
        .ps2_clk(ps2_clk),
        .ps2_data(ps2_dat),
        .nextdata_n(nextdata_n),
        .data(data),
        .sampling(sampling),
        .ready(ready),
        .overflow(overflow)
    );

    wire [7:0] display_ascii;
    scancode2ascii u_scancode2ascii (
        .scancode(scancode),
        .key_valid(key_valid),
        .ascii(ascii)
    );
    scancode2ascii u_display_ascii (
    .scancode(current_key),
    .key_valid(),
    .ascii(display_ascii)
);

    key_decoder u_key_decoder (
        .clk(clk),
        .clrn(clrn),
        .scancode(scancode),
        .scan_valid(scan_valid),
        .key_valid(key_valid),
        .count(count),
        .is_pressed(is_pressed),
        .current_key(current_key)
    );

    wire [7:0] seg0;
    wire [7:0] seg1;
    wire [7:0] seg2;
    wire [7:0] seg3;
    bcd7seg u_seg0 (.b(current_key[3:0]),   .h(seg0));
    bcd7seg u_seg1 (.b(current_key[7:4]),   .h(seg1));
    bcd7seg u_seg2 (.b(display_ascii[3:0]), .h(seg2));
    bcd7seg u_seg3 (.b(display_ascii[7:4]), .h(seg3));
    bcd7seg u_seg4 (.b(count[3:0]),         .h(seg4));
    bcd7seg u_seg5 (.b(count[7:4]),         .h(seg5));
    assign seg0_out = is_pressed ? seg0 : 8'hff;
    assign seg1_out = is_pressed ? seg1 : 8'hff;
    assign seg2_out = is_pressed ? seg2 : 8'hff;
    assign seg3_out = is_pressed ? seg3 : 8'hff;

endmodule
