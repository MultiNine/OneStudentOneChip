module ysyx_27000000_RegisterFile (
	input         clock,
	input  [31:0] wdata,
	input  [ 4:0] waddr,
	input         wen,
	input  [ 4:0] raddr1,
	input  [ 4:0] raddr2,
	output [31:0] rdata1,
	output [31:0] rdata2,
	output [31:0] a0
);
	reg [31:0] rf [15:0];
	always @(posedge clock) begin
		if (wen && (waddr != 0)) begin 
			rf[waddr[3:0]] <= wdata;
		end
	end
	
	assign rdata1 = (raddr1 == 5'd0) ? 32'b0 : rf[raddr1[3:0]];
	assign rdata2 = (raddr2 == 5'd0) ? 32'b0 : rf[raddr2[3:0]];
	assign a0 	  = rf[10];
endmodule
