module top_module (
    input clk,
    input resetn,    // active-low synchronous reset
    input x,
    input y,
    output reg f,
    output reg g
); 

    parameter A=0, SETF=2, WAITX=3, X1=4, X10=5, WAITY1=6, WAITY2=7, SETG=8, CLRG=9;
    reg [3:0] state, next_state;

    always @(*) begin
        case (state)
            A       : next_state = SETF;
            SETF    : next_state = WAITX;
            WAITX   : next_state = (x) ? X1 : WAITX;
            X1      : next_state = (x) ? X1 : X10;
            X10     : next_state = (x) ? WAITY1 : WAITX;
            WAITY1  : next_state = (y) ? SETG : WAITY2;
            WAITY2  : next_state = (y) ? SETG : CLRG;  
            SETG    : next_state = SETG;
            CLRG    : next_state = CLRG;
        endcase
    end

    always @(posedge clk) begin
        if (~resetn) begin
            state <= A;
        end
        else begin
            state <= next_state;
        end
    end

    always @(*) begin
        f = (state == SETF);
        g = ( (state == WAITY1) || (state == WAITY2) || (state == SETG) );
    end

endmodule
