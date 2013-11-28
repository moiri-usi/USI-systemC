#include <systemc.h>

SC_MODULE(Register_17bit)
{
	sc_in<bool> clk, reset_n;
	sc_in< sc_uint<17> > in;
	sc_out< sc_uint<17> > out;
	
	void set()
	{
		if (!reset_n.read())
		{
			out.write(0);
		}
		else
		{
			out.write(in.read());
		}
	}
	
	SC_CTOR(Register_17bit)
	{
		SC_METHOD(set);
		sensitive << clk.pos() << reset_n.neg();
	}
};