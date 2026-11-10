module top_move(
    input           clk,
    input           rst,
    output          VGA_HSYNC,
    output          VGA_VSYNC,
    output          VGA_BLANK_N,
    output [7:0]    VGA_R,
    output [7:0]    VGA_G,
    output [7:0]    VGA_B
);

    // 640x480分辨率下的VGA参数设置
    parameter    h_frontporch = 96;	    // 行同步负脉冲宽度
    parameter    h_active = 144;        // 行同步负脉冲宽度 + 行消隐后沿时间
    parameter    h_backporch = 784;	    // h_active + 每行 640 个像素点时间
    parameter    h_total = 800;		    // h_backporch + 行消隐前沿时间

    parameter    v_frontporch = 2;	    // 场同步负脉冲宽度                 
    parameter    v_active = 35;         // 场同步负脉冲宽度 + 场消隐后沿时间
    parameter    v_backporch = 515;     // v_active + 每场显示 480 行时间 
    parameter    v_total = 525;         // v_backporch + 场消隐前沿时间

    // 移动的图片分辨率参数
    parameter PIC_W = 100;
    parameter PIC_H = 100;

    wire [ 9:0] h_addr;
    wire [ 9:0] v_addr;
    reg  [23:0] vga_data;
    wire        valid;
    assign VGA_BLANK_N = valid;

    vga_ctrl #(
        .h_frontporch(h_frontporch),
        .h_active(h_active),
        .h_backporch(h_backporch),
        .h_total(h_total),
        .v_frontporch(v_frontporch),
        .v_active(v_active),
        .v_backporch(v_backporch),
        .v_total(v_total)
    ) u_vga_ctrl (
        .pclk(clk),
        .reset(rst),
        .vga_data(vga_data),
        .h_addr(h_addr),
        .v_addr(v_addr),
        .hsync(VGA_HSYNC),
        .vsync(VGA_VSYNC),
        .valid(valid),
        .vga_r(VGA_R),
        .vga_g(VGA_G),
        .vga_b(VGA_B)
    );

    reg [9:0] x_pos;
    reg [9:0] y_pos;
    reg       x_dir;
    reg       y_dir;

    // 每一帧更新一次图片位置
    reg VGA_VSYNC_d;
    always @(posedge clk or posedge rst) begin
        if (rst) VGA_VSYNC_d <= 1'b0;
        else VGA_VSYNC_d <= VGA_VSYNC;
    end
    wire frame_tick = VGA_VSYNC_d & ~VGA_VSYNC;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            x_pos <= 10'b0;
            y_pos <= 10'b0;
            x_dir <= 1'b1;      // right
            y_dir <= 1'b1;      // down
        end
        else if (frame_tick) begin
            if (x_dir) begin
                if (x_pos == 640 - PIC_W) begin     // 触碰右边界
                    x_dir <= 1'b0;
                    x_pos <= x_pos - 10'd1;
                end
                else x_pos <= x_pos + 10'd1;
            end
            else begin
                if (x_pos == 0) begin               // 触碰左边界
                    x_dir <= 1'b1;
                    x_pos <= x_pos + 10'd1;
                end
                else x_pos <= x_pos - 10'd1;
            end

            if (y_dir) begin
                if (y_pos == 480 - PIC_H) begin     // 触碰下边界
                    y_dir <= 1'b0;
                    y_pos <= y_pos - 10'd1;
                end
                else y_pos <= y_pos + 10'd1;
            end
            else begin
                if (y_pos == 0) begin               // 触碰上边界
                    y_dir <= 1'b1;
                    y_pos <= y_pos + 10'd1;
                end
                else y_pos <= y_pos - 10'd1;
            end
        end
    end

    // 判断当前像素是否位于图片内部
    wire pic_valid = valid                   &&
                    (h_addr >= x_pos)        &&
                    (h_addr < x_pos + PIC_W) &&
                    (v_addr >= y_pos)        &&
                    (v_addr < y_pos + PIC_H);
    
    // 将绝对坐标转换为局部坐标
    wire [9:0] x_local = h_addr - x_pos;
    wire [9:0] y_local = v_addr - y_pos;

    reg  [23:0] pic_rom [0:327679];     // 640 × 512 - 1
    wire [18:0] addr_rom = pic_valid ? {x_local, y_local[8:0]} : 19'b0;
    initial begin
        $readmemh("./pic/ysyx.hex", pic_rom);
    end
    always @(posedge clk) begin
        if (pic_valid) vga_data <= pic_rom[addr_rom];
        else vga_data <= 24'h000000;
    end

endmodule
