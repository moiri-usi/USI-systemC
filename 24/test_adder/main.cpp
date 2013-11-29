#include <systemc.h>
#include <fstream>
#include "tester.h"
#include "adder_8bit.h"
using namespace std;

int sc_main(int argc, char *argv[]) {
    sc_signal <sc_uint<8> > mod_in1, mod_in2, mod_out;
    sc_signal <bool> mod_cin, mod_enable, mod_reset_n, mod_cout;
    sc_clock clk("clock", 10, SC_NS);

    Adder_8bit module_adder("adder");
    module_adder.in1(mod_in1);
    module_adder.in2(mod_in2);
    module_adder.cin(mod_cin);
    module_adder.enable(mod_enable);
    mod_reset_n = 1;
    module_adder.reset_n(mod_reset_n);
    module_adder.out(mod_out);
    module_adder.cout(mod_cout);

    Tester testbench("testbench");
    testbench.clk(clk);
    testbench.add_in1(mod_in1);
    testbench.add_in2(mod_in2);
    testbench.add_cin(mod_cin);
    testbench.add_enable(mod_enable);

    sc_trace_file *t_file = sc_create_vcd_trace_file("test");
    sc_trace(t_file, clk, "clock");
    sc_trace(t_file, mod_in1, "a");
    sc_trace(t_file, mod_in2, "b");
    sc_trace(t_file, mod_cin, "cin");
    sc_trace(t_file, mod_enable, "enable");
    sc_trace(t_file, mod_out, "s");
    sc_trace(t_file, mod_cout, "cout");

    sc_start();
}
