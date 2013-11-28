#include <systemc.h>
#include <fstream>
#include <controller.h>
#include <tester.h>

using namespace std;

int sc_main(int argc, char *argv[])
{
	sc_clock clk("clock", 10, SC_NS);
	sc_signal<bool> s_reset_n;
	sc_signal< sc_uint<2> > s_addr_in_1, s_addr_in_2, s_addr_out; 
	sc_signal< sc_uint<3> > s_opcode;
	sc_signal<bool> s_sel_const;
	sc_signal< sc_bv<2> > s_sel_in_1, s_sel_in_2;
	sc_signal< sc_bv<3> > s_sel_op;
	sc_signal< sc_bv<4> > s_we_n;
	
	Controller module_ctrl("controller1");
	module_ctrl.clk(clk);
	module_ctrl.reset_n(s_reset_n);
	module_ctrl.addr_in_1(s_addr_in_1);
	module_ctrl.addr_in_2(s_addr_in_2);
	module_ctrl.addr_out(s_addr_out);
	module_ctrl.opcode(s_opcode);
	module_ctrl.sel_const(s_sel_const);
	module_ctrl.sel_in_1(s_sel_in_1);
	module_ctrl.sel_in_2(s_sel_in_2);
	module_ctrl.sel_op(s_sel_op);
	module_ctrl.we_n(s_we_n);
	
	tester testbench("testbench1");
	testbench.clk(clk);
	testbench.reset_n(s_reset_n);
	testbench.addr_in_1(s_addr_in_1);
	testbench.addr_in_2(s_addr_in_2);
	testbench.addr_out(s_addr_out);
	testbench.opcode(s_opcode);
	
	sc_trace_file *trace_file = sc_create_vcd_trace_file("test");
	sc_trace(trace_file, clk, "clock");
	
	sc_trace(trace_file, s_reset_n, "reset_n");
	sc_trace(trace_file, s_addr_in_1, "addr_in_1");
	sc_trace(trace_file, s_addr_in_2, "addr_in_2");
	sc_trace(trace_file, s_addr_out, "addr_out");
	sc_trace(trace_file, s_opcode, "opcode");
	
	sc_trace(trace_file, s_sel_const, "sel_const");
	sc_trace(trace_file, s_sel_in_1, "sel_in_1");
	sc_trace(trace_file, s_sel_in_2, "sel_in_2");
	sc_trace(trace_file, s_sel_op, "sel_op");
	sc_trace(trace_file, s_we_n, "we_n");
	
	sc_start();
	
	return 0;
}
