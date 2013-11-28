#include <systemc.h>
#include "execution_Unit.h"
#include "tester.h"
using namespace std;

 
int sc_main (int argc, char *argv[]){
	sc_clock clock ("clock1", 20, 0.5, 2, true);

  sc_signal <sc_uint<8> > data1,data2,data_out ;
  sc_signal <sc_bv<3> > ctrl ;
  
	Execution_Unit module_exec("Execution_Unit");
	module_exec.data_in_a(data1);
	module_exec.data_in_b(data2);
	module_exec.ctrl(ctrl);
	module_exec.data_out(data_out);
	
  
	tester testbench("testbench1");
	testbench.out1( data1 ) ;
	testbench.out2( data2 ) ;
	testbench.out3( data_out ) ;
	testbench.ctrl( ctrl ) ;
	testbench.clk( clock ) ;
  
  sc_trace_file* tf;
  tf = sc_create_vcd_trace_file("my_trace");
  sc_trace(tf, clock, "clock");
  sc_trace(tf, data1, "data1");
  sc_trace(tf, data2, "data2");
  sc_trace(tf, data_out, "data_out");
  sc_trace(tf, ctrl, "ctrl");
	sc_start(-1, SC_NS);
  sc_close_vcd_trace_file(tf);
	return 0;// Terminate simulation
	
	
}
