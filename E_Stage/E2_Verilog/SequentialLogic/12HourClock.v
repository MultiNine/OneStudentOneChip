module top_module(
    input clk,
    input reset,
    input ena,
    output reg pm,
    output reg [7:0] hh,
    output reg [7:0] mm,
    output reg [7:0] ss);

    reg [3:0] hh_one, hh_ten;
    reg [3:0] mm_one, mm_ten;
    reg [3:0] ss_one, ss_ten;

    always @(*) begin
        hh = {hh_ten, hh_one};
        mm = {mm_ten, mm_one};
        ss = {ss_ten, ss_one};
    end

    always @(posedge clk) begin
        if (reset) begin
            ss_ten <= 4'd0;
            ss_one <= 4'd0;
            mm_ten <= 4'd0;
            mm_one <= 4'd0;
            hh_ten <= 4'd1;
            hh_one <= 4'd2;
            pm <= 1'd0;
        end
        else if (ena) begin
            // 11:59:59 PM advances to 12:00:00 AM
            // 11:59:59 AM advances to 12:00:00 PM
            if (ss == 8'h59 && mm == 8'h59 && hh == 8'h11) begin
                pm <= ~pm;
                ss_one <= 4'd0;
                ss_ten <= 4'd0;
                mm_one <= 4'd0;
                mm_ten <= 4'd0;
                hh_one <= 4'd2;
                hh_ten <= 4'd1;
            end
            else if (ss == 8'h59 && mm == 8'h59) begin
                ss_one <= 4'd0;
                ss_ten <= 4'd0;
                mm_one <= 4'd0;
                mm_ten <= 4'd0;
                if (hh_one == 4'h9) begin
                    hh_ten <= 4'd1;
                    hh_one <= 4'd0;
                end
                else if (hh == 8'h12) begin
                    hh_one <= 4'd1;
                    hh_ten <= 4'd0;
                end
                else begin
                    hh_one <= hh_one + 4'd1;
                end
            end
            else if (ss == 8'h59) begin
                ss_one <= 4'd0;
                ss_ten <= 4'd0;
                if (mm_one == 4'h9) begin
                    mm_ten <= mm_ten + 4'd1;
                    mm_one <= 4'd0;
                end
                else begin
                    mm_one <= mm_one + 4'd1;
                end
            end
            else begin
                if (ss_one == 4'h9) begin
                    ss_ten <= ss_ten + 4'd1;
                    ss_one <= 4'd0;
                end
                else begin
                    ss_one <= ss_one + 4'd1;
                end
            end  
        end   
    end
endmodule
