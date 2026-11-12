module RegisterFile #(ADDR_WIDTH = 4, DATA_WIDTH = 32) (
	input 				      clk,
	input  [DATA_WIDTH - 1:0] wdata,
	input  [ADDR_WIDTH - 1:0] waddr,
	input  				      wen,
	input  [ADDR_WIDTH - 1:0] raddr1,
	input  [ADDR_WIDTH - 1:0] raddr2,
	output [DATA_WIDTH - 1:0] rdata1,
	output [DATA_WIDTH - 1:0] rdata2
);

	reg [DATA_WIDTH - 1:0] rf [2**ADDR_WIDTH - 1:0];
	always @(posedge clk) begin
		if (wen) begin 
			rf[waddr] <= wdata;
		end
	end
	
	assign rdata1 = (raddr1 == {ADDR_WIDTH{1'b0}}) ? {DATA_WIDTH{1'b0}} : rf[raddr1];
	assign rdata2 = (raddr2 == {ADDR_WIDTH{1'b0}}) ? {DATA_WIDTH{1'b0}} : rf[raddr2];

	always @(posedge clk) begin
    	$strobe("R[0]  = %08x, R[1]  = %08x, R[2]  = %08x, R[3]  = %08x", 32'h0,  rf[1],  rf[2],  rf[3]);
		$strobe("R[4]  = %08x, R[5]  = %08x, R[6]  = %08x, R[7]  = %08x", rf[4],  rf[5],  rf[6],  rf[7]);
		$strobe("R[8]  = %08x, R[9]  = %08x, R[10] = %08x, R[11] = %08x", rf[8],  rf[9],  rf[10], rf[11]);
		$strobe("R[12] = %08x, R[13] = %08x, R[14] = %08x, R[15] = %08x", rf[12], rf[13], rf[14], rf[15]);
	end	

endmodule
