module top(
    input           clk,
    input           rst,
    output          VGA_HSYNC,
    output          VGA_VSYNC,
    output          VGA_BLANK_N,
    output [7:0]    VGA_R,
    output [7:0]    VGA_G,
    output [7:0]    VGA_B
);

    //640x480分辨率下的VGA参数设置
    parameter    h_frontporch = 96;	    // 行同步负脉冲宽度
    parameter    h_active = 144;        // 行同步负脉冲宽度 + 行消隐后沿时间
    parameter    h_backporch = 784;	    // h_active + 每行 640 个像素点时间
    parameter    h_total = 800;		    // h_backporch + 行消隐前沿时间

    parameter    v_frontporch = 2;	    // 场同步负脉冲宽度                 
    parameter    v_active = 35;         // 场同步负脉冲宽度 + 场消隐后沿时间
    parameter    v_backporch = 515;     // v_active + 每场显示 480 行时间 
    parameter    v_total = 525;         // v_backporch + 场消隐前沿时间

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

    reg  [23:0] pic_rom [0:327679];     // 640 × 512 - 1
    wire [18:0] addr_rom = {h_addr, v_addr[8:0]};

    initial begin
        $readmemh("./pic/sena.hex", pic_rom);
    end

    always @(posedge clk) begin
        vga_data <= pic_rom[addr_rom];
    end

endmodule
