module LSU #(DATA_WIDTH = 32) (
    input                         is_lw,
    input                         is_sw,
    input                         is_lbu,
    input                         is_sb,
    input      [DATA_WIDTH - 1:0] memAddr,
    input      [DATA_WIDTH - 1:0] rdata2,       // 来自GPR的rdata2 供sw/sb写入存储器
    input      [DATA_WIDTH - 1:0] dataFromMem,  // 通过DPI-C从存储器读回的数据
    output                        ren,
    output                        wen,
    output     [DATA_WIDTH - 1:0] wdata,
    output reg [             7:0] wmask,
    output reg [DATA_WIDTH - 1:0] lsu_data
);

    assign wdata = is_sw ? rdata2 : (rdata2 << {memAddr[1:0], 3'b000}); 
    
    assign ren = is_lw | is_lbu;
    assign wen = is_sw | is_sb;

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
            lsu_data = dataFromMem;
        end
        else if (is_lbu) begin
            case (memAddr[1:0])
                2'b00:   lsu_data = {24'b0, dataFromMem[7:0]};
                2'b01:   lsu_data = {24'b0, dataFromMem[15:8]};
                2'b10:   lsu_data = {24'b0, dataFromMem[23:16]};
                2'b11:   lsu_data = {24'b0, dataFromMem[31:24]};
                default: lsu_data = 32'h0000_0000;
            endcase
        end 
        else begin
            lsu_data = 32'h0000_0000;
        end
    end
endmodule
