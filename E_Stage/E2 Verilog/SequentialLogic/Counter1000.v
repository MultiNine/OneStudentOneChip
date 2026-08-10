module top_module (
    input clk,
    input reset,
    output OneHertz,
    output [2:0] c_enable
); 

    wire [3:0] ones, tens, hundreds;

    assign c_enable[0] = 1'b1;                                          // 每一秒计数
    assign c_enable[1] = (ones == 4'd9) ? 1'b1 : 1'b0;                  // 计数到9进位
    assign c_enable[2] = (tens == 4'd9 && ones == 4'd9) ? 1'b1 : 1'b0;  // 计数到99进位

    bcdcount counter0 (clk, reset, c_enable[0], ones);
    bcdcount counter1 (clk, reset, c_enable[1], tens);
    bcdcount counter3 (clk, reset, c_enable[2], hundreds);

    assign OneHertz = (ones == 4'd9 && tens == 4'd9 && hundreds == 4'd9);

endmodule
