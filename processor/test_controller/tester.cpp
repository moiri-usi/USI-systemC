#include <systemc.h>
#include <tester.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

void tester::testing()
{
	bool t_reset_n;
	unsigned int t_addr_in_1, t_addr_in_2, t_addr_out, t_opcode;
	
	//wait(rand() % 10 + 1, SC_NS);
	wait();
	while(1)
	{
		if (in_file >> t_opcode >> t_addr_in_1 >> t_addr_in_2 >> t_addr_out >> t_reset_n)
		{
			opcode.write(t_opcode);
			addr_in_1.write(t_addr_in_1);
			addr_in_2.write(t_addr_in_2);
			addr_out.write(t_addr_out);
			reset_n.write(t_reset_n);
			//wait(rand() % 10 + 1, SC_NS);
			wait();
		}
		else
		{
			break;
		}
	}
	
	sc_stop();
}