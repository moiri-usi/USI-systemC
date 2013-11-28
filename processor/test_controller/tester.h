#include <systemc.h>
#include <fstream>
#include <iostream>

SC_MODULE(tester)
{
	sc_in<bool> clk;
	sc_out<bool> reset_n;
	sc_out< sc_uint<2> > addr_in_1, addr_in_2, addr_out; 
	sc_out< sc_uint<3> > opcode;
	
	ifstream in_file;
	
	void testing();
	
	SC_CTOR(tester)
	{
		SC_THREAD(testing);
		sensitive << clk.pos();
		in_file.open("test.in");
	}
};		