module top_module(
    input clk,
    input areset,    // Freshly brainwashed Lemmings walk left.
    input bump_left,
    input bump_right,
    input ground,
    input dig,
    output walk_left,
    output walk_right,
    output aaah,
    output digging ); 

    parameter LEFT=0, RIGHT=1, FALL_LEFT=2, FALL_RIGHT=3, DIG_LEFT=4, DIG_RIGHT=5;
    reg [2:0] state, next_state;

    always @(*) begin
        // State transition logic
        case (state) 
            LEFT:  begin
                if (~ground)
                    next_state = FALL_LEFT;
                else if (dig & ground)
                    next_state = DIG_LEFT;
                else if (bump_left)
                    next_state = RIGHT;
                else
                    next_state = LEFT;    
            end
            RIGHT: begin
                if (~ground)
                    next_state = FALL_RIGHT;
                else if (dig & ground)
                    next_state = DIG_RIGHT;
                else if (bump_right)
                    next_state = LEFT;
                else
                    next_state = RIGHT;
            end
            FALL_LEFT:  begin
                next_state = (ground == 0) ? FALL_LEFT : LEFT;
                
            end
            FALL_RIGHT: begin
                next_state = (ground == 0) ? FALL_RIGHT : RIGHT;
                
            end
            DIG_LEFT:   begin
                next_state = (ground == 0) ? FALL_LEFT : DIG_LEFT;
            end
            DIG_RIGHT:  begin
                next_state = (ground == 0) ? FALL_RIGHT : DIG_RIGHT;
            end
        endcase
    end

    always @(posedge clk, posedge areset) begin
        // State flip-flops with asynchronous reset
        if (areset) begin
            state <= LEFT;
        end
        else begin
            state <= next_state;
        end
    end

    // Output logic
    assign walk_left = (state == LEFT);
    assign walk_right = (state == RIGHT);
    assign aaah = (state == FALL_LEFT) || (state == FALL_RIGHT);
    assign digging = (state == DIG_LEFT) || (state == DIG_RIGHT);

endmodule
