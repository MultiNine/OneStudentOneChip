module lfsr(clk, rst, dout, segout1, segout0);
    input             clk;
    input             rst;
    output reg  [7:0] dout;
    output      [7:0] segout1;
    output      [7:0] segout0;

    wire feedback;
    assign feedback = dout[4] ^ dout[3] ^ dout[2] ^ dout[0];

    bcd7seg seg1 (.b(dout[7:4]), .h(segout1));
    bcd7seg seg0 (.b(dout[3:0]), .h(segout0));

    always@(posedge clk or posedge rst) begin
        if(rst) begin
            dout <= 8'b0000_0001;
        end
        else begin
            dout <= {feedback, dout[7:1]};
        endgit
    end

endmodule
