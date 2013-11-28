#include <systemc.h>

SC_MODULE(Mux_2to1_8bit)
{
	sc_in<bool> select;
	sc_in< sc_uint<8> > in1, in2;
	sc_out< sc_uint<8> > out;
	
	void mux()
	{
		if (!select.read())
		{
			out.write(in1.read());
		}
		else
		{
			out.write(in2.read());
		}
	}
	
	SC_CTOR(Mux_2to1_8bit)
	{
		SC_METHOD(mux);
		sensitive << select << in1 << in2;
	}
};