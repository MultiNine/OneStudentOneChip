// Note the Verilog-1995 module declaration syntax here:
module top_module(clk, reset, in, out);
    input clk;
    input reset;    // Synchronous reset to state B
    input in;
    output out;//  
    reg out;

    // Fill in state name declarations
    parameter A = 0, B = 1;

    reg present_state, next_state;

    always @(posedge clk) begin
        if (reset) begin  
            // Fill in reset logic
            present_state <= B;
            out <= 1'b1;
        end else begin
            case (present_state)
                // Fill in state transition logic
                A: begin
                    next_state = (in == 0) ? B : A;
                end
                B: begin
                    next_state = (in == 0) ? A : B;
                end
            endcase

            // State flip-flops
            present_state = next_state;   

            case (present_state)
                // Fill in output logic
                A: out = 1'b0;
                B: out = 1'b1;
            endcase
        end
    end

endmodule
