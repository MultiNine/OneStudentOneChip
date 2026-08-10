module top_module (
    input clk,
    input areset,
    input x,
    output z
);

    parameter LOW0=0, OUT0=1, OUT1=2;
    reg [2:0] state, next_state;

    always @(*) begin
        case (state)
            LOW0:   next_state = (x == 1'b0) ? LOW0 : OUT1;
            OUT0:   next_state = (x == 1'b0) ? OUT1 : OUT0;
            OUT1:   next_state = (x == 1'b0) ? OUT1 : OUT0;
        endcase
    end 

    always @(posedge clk or posedge areset) begin
        if (areset) begin
            state <= LOW0;
        end
        else begin
            state <= next_state;
        end
    end

    assign z = (state == OUT1);

endmodule
