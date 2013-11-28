#include <systemc.h>
#include "register_File.h"
#include "tester.h"
using namespace std;

 
int sc_main (int argc, char *argv[]){
	sc_clock clock ("clock1", 20, 0.5, 2, true);

  sc_signal <sc_uint<8> > data1,data2,data3,data4 ;
  sc_signal <sc_uint<8> > in ;
  sc_signal <sc_bv<4> > we_n ;
  
	sc_signal<bool> reset;	
  
  
	Register_File module_reg1bit("Register_File");
	module_reg1bit.data_in(in);
	module_reg1bit.reset_n(reset);
	module_reg1bit.we_n(we_n);
	module_reg1bit.clock(clock);
	module_reg1bit.data_out1(data1) ;
	module_reg1bit.data_out2(data2) ;
	module_reg1bit.data_out3(data3) ;
	module_reg1bit.data_out4(data4) ;
  
  
	tester testbench("testbench1");
	testbench.out1( data1 ) ;
	testbench.out2( data2 ) ;
	testbench.out3( data3 ) ;
	testbench.out4( data4 ) ;
	testbench.in( in ) ;
	testbench.clk( clock ) ;
	testbench.we( we_n ) ;
  
	testbench.reset( reset ) ;
  
  sc_trace_file* tf;
  tf = sc_create_vcd_trace_file("my_trace");
  sc_trace(tf, clock, "clock");
  sc_trace(tf, data1, "data1");
  sc_trace(tf, data2, "data2");
  sc_trace(tf, data3, "data3");
  sc_trace(tf, data4, "data4");
  sc_trace(tf, in, "data_in");
  sc_trace(tf, we_n, "we_n");
  sc_trace(tf, reset, "reset");
	sc_start(-1, SC_NS);
  sc_close_vcd_trace_file(tf);
	return 0;// Terminate simulation
	
	
}
