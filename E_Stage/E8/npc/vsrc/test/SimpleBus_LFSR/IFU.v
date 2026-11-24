
module IFU #(PC_WIDTH = 32, DATA_WIDTH = 32) (
    input                       clk,
    input                       rst,
    input      [PC_WIDTH - 1:0] PCin,
    input                       is_mem,
    input                       lsu_respValid,
    input                       ifu_respValid,

    output     [DATA_WIDTH - 1:0] ifu_raddr,
    output reg [PC_WIDTH - 1:0]  PCout,
    output                       instr_valid,
    output                       instr_finish,
    output                       ifu_reqValid
);
    reg [7:0] ifu_lfsr;
    wire feedback;
    assign feedback = ifu_lfsr[4] ^ ifu_lfsr[3] ^ ifu_lfsr[2] ^ ifu_lfsr[0];
    wire [7:0] ifu_lfsr_next = {feedback, ifu_lfsr[7:1]};

    wire [5:0] ifu_delay = {1'b0, ifu_lfsr_next[4:0]} + 6'd1;
    reg [5:0] ifu_delay_cnt;

    parameter IDLE = 1'b0, WAIT = 1'b1;
    reg state, next_state;

    always @(posedge clk) begin
        if (rst) begin
            state         <= IDLE;
            ifu_lfsr      <= 8'b0000_0001;
            ifu_delay_cnt <= 6'd1;
        end
        else begin
            state <= next_state;
            if (instr_finish) begin
                ifu_lfsr      <= ifu_lfsr_next;
                ifu_delay_cnt <= ifu_delay;
            end
            else if ((state == IDLE) &&
                     (ifu_delay_cnt != 6'd0)) begin
                ifu_delay_cnt <= ifu_delay_cnt - 6'd1;
            end
        end
    end

    always @(*) begin
        case (state)
            IDLE: next_state = (ifu_delay_cnt == 6'd0) ? WAIT : IDLE;
            WAIT: next_state = instr_finish ? IDLE : WAIT;
            default:
                next_state = IDLE;
        endcase
    end

    assign ifu_raddr = PCout;
    assign instr_valid = !rst && (state == WAIT) && ifu_respValid;
    assign instr_finish = !rst && (state == WAIT) && 
                        ((!is_mem && ifu_respValid) || ( is_mem && lsu_respValid));
    assign ifu_reqValid = !rst && (state == IDLE) && (ifu_delay_cnt == 6'd0);

    always @(posedge clk) begin
        if (rst) begin
            PCout <= 32'h8000_0000;
        end
        else if (instr_finish) begin
            PCout <= PCin;
        end
    end
endmodule
