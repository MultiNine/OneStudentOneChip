module top_module (
    input clk,
    input reset,
    input [3:1] s,
    output reg fr3,
    output reg fr2,
    output reg fr1,
    output reg dfr
);

    parameter S0=0, S12=1, S23=2,
              S4=3, S32=4, S21=5;
    reg [2:0] state, next_state;

    always @(*) begin
        case (state)
            S0:  begin
                next_state = (s == 3'b001) ? S12 : S0;
            end
            S12: begin
                next_state = (s == 3'b000) ? S0 : (s == 3'b011) ? S23 : S12;
            end
            S23: begin
                next_state = (s == 3'b001) ? S21 : (s == 3'b111) ? S4 : S23;
            end
            S4:  begin
                next_state = (s == 3'b011) ? S32 : S4;
            end
            S32: begin
                next_state = (s == 3'b111) ? S4 : (s == 3'b001) ? S21 : S32;
            end
            S21: begin
                next_state = (s == 3'b011) ? S23 : (s == 3'b000) ? S0 : S21;
            end
        endcase
    end

    always @(posedge clk) begin
        if (reset) begin
            state <= S0;
        end
        else begin
            state <= next_state;
        end
    end

    always @(*) begin
        case (state)
            S0:     {fr3, fr2, fr1, dfr} = 4'b1111;
            S12:    {fr3, fr2, fr1, dfr} = 4'b0110;
            S23:    {fr3, fr2, fr1, dfr} = 4'b0010;
            S4:     {fr3, fr2, fr1, dfr} = 4'b0000;
            S32:    {fr3, fr2, fr1, dfr} = 4'b0011;
            S21:    {fr3, fr2, fr1, dfr} = 4'b0111;
        endcase
    end
endmodule
