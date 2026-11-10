module mealyfsm(clk, reset, x, z);
    input   clk;
    input   reset;
    input   x;
    output  z;

    parameter [2:0] A = 0, B = 1, C = 2, D = 3, F = 4, G = 5, H = 6;
    wire      [2:0] state, next_state;
    wire            state_wen;
    assign state_wen = 1'b1;

    Reg #(3, 0) state_dff(clk, reset, next_state, state, state_wen);

    MuxKeyWithDefault #(7, 3, 3) stateMux (
        .out(next_state),
        .key(state),
        .default_out(3'b000),
        .lut( {
            A, x ? F : B,
            B, x ? F : C,
            C, x ? F : D,
            D, x ? F : D,
            F, x ? G : B,
            G, x ? H : B,
            H, x ? H : B
        } )
    );

    MuxKeyWithDefault #(2, 3, 1) outMux (
        .out(z),
        .key(state),
        .default_out(1'b0),
        .lut( {
            D, ~x,
            H,  x
        } )
    );

endmodule
