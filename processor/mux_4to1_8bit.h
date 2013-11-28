#include <systemc.h>

SC_MODULE(Mux_4to1_8bit)
{
	sc_in< sc_bv<2> > select;
	sc_in< sc_uint<8> > in1, in2, in3, in4;
	sc_out< sc_uint<8> > out;
	
	void mux()
	{
		switch((select.read()).to_uint())
		{
			case 0:
			{
				out.write(in1.read());
				break;
			}
			case 1:
			{
				out.write(in2.read());
				break;
			}
			case 2:
			{
				out.write(in3.read());
				break;
			}
			case 3:
			{
				out.write(in4.read());
				break;
			}
		}
	}
	
	SC_CTOR(Mux_4to1_8bit)
	{
		SC_METHOD(mux);
		sensitive << select << in1 << in2 << in3 << in4;
	}
};