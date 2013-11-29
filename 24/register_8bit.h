#include <systemc.h>

SC_MODULE(Register_8bit)
{
	sc_in<bool> clk, enable, reset_n;
	sc_in< sc_uint<8> > in;
	sc_out< sc_uint<8> > out;

	void set()
	{
		if (!reset_n.read())
		{
			out.write(0);
		}
		else if (enable.read())
		{
			out.write(in.read());
		}
	}

	SC_CTOR(Register_8bit)
	{
		SC_METHOD(set);
		sensitive << clk.pos() << reset_n.neg();
	}
};
