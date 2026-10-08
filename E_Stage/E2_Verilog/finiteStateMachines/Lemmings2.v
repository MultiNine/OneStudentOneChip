module top_module(
    input clk,
    input areset,    // Freshly brainwashed Lemmings walk left.
    input bump_left,
    input bump_right,
    input ground,
    output walk_left,
    output walk_right,
    output aaah ); 

    parameter LEFT=0, RIGHT=1, FALL_LEFT=2, FALL_RIGHT=3;
    reg [1:0] state, next_state;

    always @(*) begin
        // State transition logic
        case (state) 
            LEFT:  begin
                next_state = (ground == 0) ? FALL_LEFT : bump_left ? RIGHT : LEFT;
                
            end
            RIGHT: begin
                next_state = (ground == 0) ? FALL_RIGHT : bump_right ? LEFT : RIGHT;
                
            end
            FALL_LEFT:  begin
                next_state = (ground == 0) ? FALL_LEFT : LEFT;
                
            end
            FALL_RIGHT:  begin
                next_state = (ground == 0) ? FALL_RIGHT : RIGHT;
                
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
    assign aaah = state == FALL_LEFT || state == FALL_RIGHT;

endmodule
