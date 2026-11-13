module LSU #(DATA_WIDTH = 32) (
    input                         is_lw,
    input                         is_sw,
    input                         is_lbu,
    input                         is_sb,
    input      [DATA_WIDTH - 1:0] memAddr,
    input      [DATA_WIDTH - 1:0] rdata2,    // 来自GPR的rdata2 供sw/sb写入存储器
    output reg [DATA_WIDTH - 1:0] lsu_data
);
    
    import "DPI-C" function int pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(
        input int waddr, input int wdata, input byte wmask);

    wire                    ren, wen;
    reg  [             7:0] wmask;
    wire [DATA_WIDTH - 1:0] waddr = memAddr;
    wire [DATA_WIDTH - 1:0] wdata = is_sw ? rdata2 : (rdata2 << {memAddr[1:0], 3'b000});
    wire [DATA_WIDTH - 1:0] raddr = memAddr;
    reg  [DATA_WIDTH - 1:0] rdata;  // 通过DPI-C从存储器读回的数据
    
    assign ren = is_lw | is_lbu;
    assign wen = is_sw | is_sb;

    
    always @(*) begin
        if (ren) begin
            rdata = pmem_read(raddr);
        end
        else begin
            rdata = 32'b0;
        end

        if (wen) begin
            pmem_write(waddr, wdata, wmask);
        end
    end

    always @(*) begin
        if (is_sw) begin
            wmask = 8'b1111;
        end
        else if (is_sb) begin
            case (memAddr[1:0])
                2'b00:   wmask = 8'b0001;
                2'b01:   wmask = 8'b0010;
                2'b10:   wmask = 8'b0100;
                2'b11:   wmask = 8'b1000;
                default: wmask = 8'b0000;
            endcase
        end
        else begin
            wmask = 8'b0000;
        end
    end

    always @(*) begin
        if (is_lw) begin
            lsu_data = rdata;
        end
        else if (is_lbu) begin
            case (memAddr[1:0])
                2'b00:   lsu_data = {24'b0, rdata[7:0]};
                2'b01:   lsu_data = {24'b0, rdata[15:8]};
                2'b10:   lsu_data = {24'b0, rdata[23:16]};
                2'b11:   lsu_data = {24'b0, rdata[31:24]};
                default: lsu_data = 32'h0000_0000;
            endcase
        end 
        else begin
            lsu_data = 32'h0000_0000;
        end
    end

endmodule
