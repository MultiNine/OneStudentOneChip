module vga_ctrl(
    input           pclk,     // 25MHz时钟
    input           reset,    // 置位
    input  [23:0]   vga_data, // 上层模块提供的VGA颜色数据
    output [9:0]    h_addr,   // 提供给上层模块的当前扫描像素点坐标
    output [9:0]    v_addr,
    output          hsync,    // 行同步和列同步信号
    output          vsync,
    output          valid,    // 消隐信号, 0表示处于消隐
    output [7:0]    vga_r,    // 红绿蓝颜色信号
    output [7:0]    vga_g,
    output [7:0]    vga_b
    );

  //640x480分辨率下的VGA参数设置
  parameter    h_frontporch = 96;	  // 行同步负脉冲宽度
  parameter    h_active = 144;		  // 行同步负脉冲宽度 + 行消隐后沿时间
  parameter    h_backporch = 784;	  // h_active + 每行 640 个像素点时间
  parameter    h_total = 800;		    // h_backporch + 行消隐前沿时间

  parameter    v_frontporch = 2;	  // 场同步负脉冲宽度                 
  parameter    v_active = 35;       // 场同步负脉冲宽度 + 场消隐后沿时间
  parameter    v_backporch = 515;   // v_active + 每场显示 480 行时间 
  parameter    v_total = 525;       // v_backporch + 场消隐前沿时间     

  // 像素计数值
  reg [9:0]    x_cnt;	  // 行像素计数
  reg [9:0]    y_cnt;	  // 列像素计数
  wire         h_valid;	// 行消隐信号
  wire         v_valid;	// 场消隐信号

  always @(posedge reset or posedge pclk)
      if (reset == 1'b1)
        x_cnt <= 1;
      else
      begin
        if (x_cnt == h_total)
            x_cnt <= 1;
        else
            x_cnt <= x_cnt + 10'd1;
      end

  always @(posedge reset or posedge pclk)
      if (reset == 1'b1)
        y_cnt <= 1;
      else
      begin
        if (y_cnt == v_total & x_cnt == h_total)
            y_cnt <= 1;
        else if (x_cnt == h_total)	// 扫描完一行
            y_cnt <= y_cnt + 10'd1;
      end

  // 生成同步信号
  assign hsync = (x_cnt > h_frontporch);
  assign vsync = (y_cnt > v_frontporch);

  // 生成消隐信号
  assign h_valid = (x_cnt > h_active) & (x_cnt <= h_backporch);
  assign v_valid = (y_cnt > v_active) & (y_cnt <= v_backporch);
  assign valid = h_valid & v_valid;

  // 计算当前有效像素坐标
  assign h_addr = h_valid ? (x_cnt - 10'd145) : {10{1'b0}};
  assign v_addr = v_valid ? (y_cnt - 10'd36) : {10{1'b0}};

  // 设置输出的颜色值
  assign vga_r = vga_data[23:16];
  assign vga_g = vga_data[15:8];
  assign vga_b = vga_data[7:0];

endmodule
