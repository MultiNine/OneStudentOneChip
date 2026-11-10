module key_decoder (
    input            clk,           // 系统时钟
    input            clrn,          // 低有效同步复位
    input      [7:0] scancode,      // 来自键盘扫描模块的扫描码
    input            scan_valid,    // 是否输入了扫描码
    input            key_valid,     // 当前扫描码有效
    output reg [7:0] count,         // 按键次数
    output reg       is_pressed,    // 是否有按键被按下还未释放
    output reg [7:0] current_key    // 当前按下案件的扫描码
);

    reg break_pending;              // 已收到 F0，等待后续扫描码

    always @(posedge clk) begin
        if (!clrn) begin
            is_pressed    <= 1'b0;
            break_pending <= 1'b0;
            count         <= 8'd0;
            current_key   <= 8'h00;
        end
        else begin
            if (scan_valid) begin
                if (scancode == 8'hF0) begin
                    break_pending <= 1'b1;
                end
                else if (break_pending) begin           // 处理释放事件
                    break_pending <= 1'b0;
                    if (scancode == current_key) begin
                        is_pressed <= 1'b0;
                    end
                end
                else if (!is_pressed && key_valid) begin // 处理新的按下事件
                    is_pressed  <= 1'b1;
                    current_key <= scancode;
                    count       <= count + 8'd1;
                end
                else begin                              // 长按重复码或不支持的键码
                    // do nothing.
                end
            end
        end
    end

endmodule