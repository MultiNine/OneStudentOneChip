module top_module (
    input clk,
    input w, R, E, L,
    output reg Q
);

    wire muxOut, D;
    assign muxOut = E ? w : Q;
    assign D      = L ? R : muxOut;

    always @(posedge clk) begin
        Q <= D;
    end

endmodule
