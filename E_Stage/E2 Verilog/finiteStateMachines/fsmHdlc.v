module top_module(
    input clk,
    input reset,    // Synchronous reset
    input in,
    output disc,
    output flag,
    output err);

    parameter START=0, DATA=1, DISC=2, FLAG=3, ERROR=4;
    reg [2:0] state, next_state;
    reg [2:0] count;

    always @(*) begin
        case (state)
            START: begin    
               next_state = (in == 1'b0) ? START : DATA;
            end
            DATA: begin
                if (in == 1'b0) begin
                    if (count == 3'd4) begin        // 收到5个连续1
                        next_state = DISC;
                    end
                    else if (count == 3'd5) begin   // 收到6个连续1
                        next_state = FLAG;
                    end
                    else begin    // 收到连续1的个数小于5
                        next_state = START;
                    end
                    
                end
                else begin
                    if (count > 3'd4) begin
                        next_state = ERROR;         // 已经收到连续6个1且当前in为1，则直接进入ERROR
                    end
                    else begin
                        next_state = DATA;
                    end
                end
            end
            DISC: begin
                next_state = (in == 1'b0) ? START : DATA;
            end
            FLAG: begin
                next_state = (in == 1'b0) ? START : DATA;
            end
            ERROR: begin
                next_state = (in == 1'b1) ? ERROR : START;
            end
        endcase
        
    end

    always @(posedge clk) begin
        if (reset) begin
            state <= START;
            count <= 3'd0;
        end
        else begin
            state <= next_state;
            if (state == DATA && in) begin
                if (count < 3'd5) begin
                    count <= count + 1;
                end
                else begin
                    count <= count;
                end
            end
            else begin
                count <= 3'd0;
            end
        end
    end

    assign disc = (state == DISC);
    assign flag = (state == FLAG);
    assign err  = (state == ERROR);

endmodule
