
VERILOG = iverilog
TARGET = top.vcd

$(TARGET) : top.vvp
	vvp top.vvp

top.vvp: lab_4_tb.v top.v adder.v alu.v aludec.v controller.v datapath.v eqcmp.v flopenr.v flopenrc.v flopr.v floprc.v hazard.v maindec.v mips.v mux2.v mux3.v pc.v regfile.v signext.v sl2.v 
	$(VERILOG) -o top.vvp lab_4_tb.v top.v adder.v alu.v aludec.v controller.v datapath.v eqcmp.v flopenr.v flopenrc.v flopr.v floprc.v hazard.v maindec.v mips.v mux2.v mux3.v pc.v regfile.v signext.v sl2.v 

clean:
	rm $(TARGET)