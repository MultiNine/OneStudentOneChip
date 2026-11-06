module addSub4bit(a, b, ctrl, carry, zero, overflow, result);
    input   [3:0]   a;
    input   [3:0]   b;
    input           ctrl;   // 1 sub, 0 add
    output          carry;
    output          zero;
    output          overflow;
    output  [3:0]   result;

    wire [3:0] bin;
    wire [4:0] c_r;
    
    assign bin      = b ^ {4{ctrl}};
    assign c_r      = {1'b0, a} + {1'b0, bin} + ctrl;
    assign result   = c_r[3:0];
    assign carry    = c_r[4];
    assign zero     = ~(|result);
    assign overflow = (a[3] == bin[3]) && (result[3] != a[3]);
    
endmodule
