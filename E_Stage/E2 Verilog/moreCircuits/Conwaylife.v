module top_module(
    input clk,
    input load,
    input [255:0] data,
    output reg [255:0] q );

    integer row, col;
    reg [3:0] count = 4'd0;
    reg [3:0] up, down, left, right;
    reg [255:0] qnext;

    always @(*) begin
        for (row = 0; row < 16; row = row+1) begin
            for (col = 0; col < 16; col = col+1) begin
                up    = (row == 0)  ?  4'd15 : (row - 1);
                down  = (row == 15) ?  4'd0  : (row + 1);
                left  = (col == 0)  ?  4'd15 : (col - 1);
                right = (col == 15) ?  4'd0  : (col + 1);
                count = q[up*16  +left] + q[up*16  +col] + q[up*16  +right]
                      + q[row*16 +left]                  + q[row*16 +right]
                      + q[down*16+left] + q[down*16+col] + q[down*16+right];
                case (count)
                    4'd2:    qnext[row*16 + col] = q[row*16 + col];
                    4'd3:    qnext[row*16 + col] = 1'b1;
                    default: qnext[row*16 + col] = 1'b0;
                endcase
            end
        end
    end

    always @(posedge clk) begin
        if (load) begin
            q <= data;
        end
        else begin
            q <= qnext;
        end
    end
endmodule