#include <controller.h>

void Controller::control()
{
	if (!reset_n.read())
	{
		sel_const.write(0);
		sel_in_1.write(0);
		sel_in_2.write(0);
		sel_op.write(0);
		we_n.write("1111");
		
		s_sel_op_mem.write(0);
		s_we_mem1_n.write("1111");
		s_we_mem2_n.write("1111");
		
	}
	else
	{	
		sel_in_1.write(static_cast< sc_bv<3> > (addr_in_1.read()));
		sel_in_2.write(static_cast< sc_bv<3> > (addr_in_2.read()));
		
		sc_bv<4> tmp_we_n;
		if (opcode.read() == 0)
		{
			tmp_we_n = "1111";
		}
		else if (addr_out.read() == 0)
		{
			tmp_we_n = "1110";
		}
		else if (addr_out.read() == 1)
		{
			tmp_we_n = "1101";
		}
		else if (addr_out.read() == 2)
		{
			tmp_we_n = "1011";
		}
		else
		{
			tmp_we_n = "0111";
		}
		s_we_mem1_n.write(tmp_we_n);
		s_we_mem2_n.write(s_we_mem1_n.read());
		we_n.write(s_we_mem2_n.read());
		
		s_sel_op_mem.write(static_cast< sc_bv<3> > (opcode.read()));
		sel_op.write(s_sel_op_mem.read());
		
		sel_const.write((opcode.read() == 1) | (opcode.read() == 5));
	}
}
