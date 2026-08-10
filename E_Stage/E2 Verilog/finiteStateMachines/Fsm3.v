module top_module(
    input clk,
    input in,
    input areset,
    output out); //

    // State transition logic
    parameter A=0, B=1, C=2, D=3;
    reg [1:0] state, next_state;

    always @(*) begin
        case (state)
            A: begin
                next_state = (in == 0) ? A : B;
            end
            B: begin
                next_state = (in == 0) ? C : B;
            end
            C: begin
                next_state = (in == 0) ? A : D;
            end
            D: begin
                next_state = (in == 0) ? C : B;
            end
        endcase
    end

    // State flip-flops with asynchronous reset
    always @(posedge clk or posedge areset) begin
        if (areset) begin
            state <= A;
        end
        else begin
            state <= next_state;
        end
    end

    // Output logic
    assign out = (state == D);
endmodule
