create_project vp "C:/Users/MultiNine/logisim_evolution_workspace/Full_Adder/FA/sandbox//vp"
set_property part xc7a35tftg256-1 [current_project]
set_property target_language VHDL [current_project]
add_files "C:/Users/MultiNine/logisim_evolution_workspace/Full_Adder/FA/verilog/circuit/FA.v"
add_files "C:/Users/MultiNine/logisim_evolution_workspace/Full_Adder/FA/verilog/gates/AND_GATE.v"
add_files "C:/Users/MultiNine/logisim_evolution_workspace/Full_Adder/FA/verilog/gates/OR_GATE.v"
add_files "C:/Users/MultiNine/logisim_evolution_workspace/Full_Adder/FA/verilog/gates/XOR_GATE_ONEHOT.v"
add_files "C:/Users/MultiNine/logisim_evolution_workspace/Full_Adder/FA/verilog/toplevel/logisimTopLevelShell.v"
add_files -fileset constrs_1 "C:/Users/MultiNine/logisim_evolution_workspace/Full_Adder/FA/xdc/vivadoConstraints.xdc"
exit
