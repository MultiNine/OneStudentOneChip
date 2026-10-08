module top_module (
    input clk,
    input reset,   // Synchronous reset
    input s,
    input w,
    output reg z
);

    parameter A=0, B=1;
    reg state, next_state;
    reg [1:0] count, cycle;

    always @(*) begin
        case (state) 
            A: begin
                next_state = (s == 1'b0) ? A : B;
            end
            B: begin
                next_state = B;
            end
        endcase
    end

    always @(posedge clk) begin
        if (reset) begin
            state <= A;
            cycle <= 2'd0;
            count <= 2'd0;
            z <= 1'd0;
        end
        else begin
            state <= next_state;
            if (state == B) begin
                if (cycle == 2'd2) begin    // 当前w是本组第3个输入
                    z <= ( (count + w) == 2'd2 );
                    cycle <= 2'd0;
                    count <= 2'd0;
                end
                else begin
                    cycle <= cycle + 2'd1;
                    z <= 1'd0;      
                    if (w) begin
                        count <= count + 2'd1;
                    end
                end   
            end
            else begin
                cycle <= 2'd0;
                count <= 2'd0;
                z <= 1'd0;
            end
        end
    end

endmodule
