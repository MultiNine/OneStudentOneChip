`timescale 1ns/1ps

module tb_ALU;
    reg  [3:0] inputa, inputb;
    reg  [2:0] inputaluop;
    wire [3:0] outputs;
    wire outputc, outputof, outputz;

    integer i, j, op, k;
    integer total_tests, failed_tests;
    reg [3:0] expected;
    reg [4:0] sum_ext;
    reg exp_c, exp_of, exp_z;
    reg check_flags;	// 判断要不要检查进位、零标志和溢出

    ALU dut (
        .A(inputa),
        .B(inputb),
        .aluop(inputaluop),
        .out(outputs),
        .carry(outputc),
        .overflow(outputof),
        .zero(outputz)
    );

    task check;
        input [3:0] results;
        input resultof, resultc, resultz;
        input check_flags_en;
        reg failed;
        begin
            failed = 0;
            total_tests = total_tests + 1;

            if (outputs !== results) begin
                $display("FAIL: A=%h B=%h op=%b out expected=%h got=%h",
                         inputa, inputb, inputaluop, results, outputs);
                failed = 1;
            end

            if (check_flags_en) begin
                if (outputof !== resultof) begin
                    $display("FAIL: A=%h B=%h op=%b overflow expected=%b got=%b",
                             inputa, inputb, inputaluop, resultof, outputof);
                    failed = 1;
                end
                if (outputc !== resultc) begin
                    $display("FAIL: A=%h B=%h op=%b carry expected=%b got=%b",
                             inputa, inputb, inputaluop, resultc, outputc);
                    failed = 1;
                end
                if (outputz !== resultz) begin
                    $display("FAIL: A=%h B=%h op=%b zero expected=%b got=%b",
                             inputa, inputb, inputaluop, resultz, outputz);
                    failed = 1;
                end
            end

            if (failed)
                failed_tests = failed_tests + 1;
        end
    endtask

    initial begin
        $dumpfile("wave.fst");
        $dumpvars(0, tb_ALU);

        total_tests = 0;
        failed_tests = 0;
        inputa = 0;
        inputb = 0;
        inputaluop = 0;

        for (op = 0; op < 8; op = op + 1) begin
            for (i = -8; i <= 7; i = i + 1) begin
                for (j = -8; j <= 7; j = j + 1) begin
                    inputa = i[3:0];
                    inputb = j[3:0];
                    inputaluop = op[2:0];

                    expected = 4'b0000;
                    exp_of = 0;
                    exp_c = 0;
                    exp_z = 0;
                    check_flags = 0;

                    case (inputaluop)
                        3'b000: begin	// ADD
                            k = i + j;
                            expected = k[3:0];
                            sum_ext = {1'b0, inputa} + {1'b0, inputb};
                            exp_c = sum_ext[4];
                            exp_of = (k > 7) || (k < -8);
                            exp_z = (expected == 4'b0000);
                            check_flags = 1;
                        end
                        3'b001: begin	// SUB
                            k = i - j;
                            expected = k[3:0];
                            exp_c = (inputa >= inputb);		// 1 代表没有借位
                            exp_of = (k > 7) || (k < -8);
                            exp_z = (expected == 4'b0000);
                            check_flags = 1;
                        end
                        3'b010: expected = ~inputa;                	// NOT
                        3'b011: expected = inputa & inputb;       	// AND
                        3'b100: expected = inputa | inputb;       	// OR
                        3'b101: expected = inputa ^ inputb;       	// XOR
                        3'b110: expected = (i < j) ? 4'd1 : 4'd0;  	// signed SLT
                        3'b111: expected = (i == j) ? 4'd1 : 4'd0; 	// EQ
                    endcase

                    #20;
                    check(expected, exp_of, exp_c, exp_z, check_flags);
                end
            end
        end

        if (failed_tests == 0)
            $display("PASS: %0d/%0d tests passed", total_tests, total_tests);
        else
            $fatal(1, "FAIL: %0d/%0d tests failed", failed_tests, total_tests);

        $finish;
    end
endmodule
