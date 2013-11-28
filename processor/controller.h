#include <systemc.h>

SC_MODULE(Controller)
{
	sc_in<bool> clk, reset_n;
	sc_in< sc_uint<2> > addr_in_1, addr_in_2, addr_out; 
	sc_in< sc_uint<3> > opcode;
	sc_out<bool> sel_const;
	sc_out< sc_bv<2> > sel_in_1, sel_in_2;
	sc_out< sc_bv<3> > sel_op;
	sc_out< sc_bv<4> > we_n;
	
	sc_signal< sc_bv<3> > s_sel_op_mem;
	sc_signal< sc_bv<4> > s_we_mem1_n, s_we_mem2_n;
	
	void control();
		
	SC_CTOR(Controller)
	{	
		s_we_mem1_n.write("1111");
		s_we_mem2_n.write("1111");
		
		SC_METHOD(control);
		sensitive << clk.pos() << reset_n.neg();
	}
};