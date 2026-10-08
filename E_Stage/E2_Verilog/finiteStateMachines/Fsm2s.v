module top_module(
    input clk,
    input reset,    // Synchronous reset to OFF
    input j,
    input k,
    output out); //  

    parameter OFF=0, ON=1; 
    reg state, next_state;

    always @(*) begin
        // State transition logic
        case (state)
            OFF: begin
                next_state = (j == 1);
            end
            ON: begin
                next_state = (k == 0);
            end
        endcase
    end

    always @(posedge clk) begin
        // State flip-flops with synchronous reset
        if (reset) begin
            state <= OFF;
        end
        else begin
            state <= next_state;
        end
    end

    // Output logic
    assign out = (state == ON);

endmodule
