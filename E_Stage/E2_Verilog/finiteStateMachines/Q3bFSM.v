module top_module (
    input clk,
    input reset,   // Synchronous reset
    input x,
    output z
);

    reg [2:0] y, Y;

    always @(*) begin
        case (y)
            3'b000: Y = (x == 1'b0) ? 3'b000 : 3'b001;
            3'b001: Y = (x == 1'b0) ? 3'b001 : 3'b100;
            3'b010: Y = (x == 1'b0) ? 3'b010 : 3'b001;
            3'b011: Y = (x == 1'b0) ? 3'b001 : 3'b010;
            3'b100: Y = (x == 1'b0) ? 3'b011 : 3'b100;
        endcase
    end

    always @(posedge clk) begin
        if (reset) begin
            y <= 3'b000;
        end
        else begin
            y <= Y;
        end
    end

    assign z = (y == 3'b011) || (y == 3'b100);

endmodule
