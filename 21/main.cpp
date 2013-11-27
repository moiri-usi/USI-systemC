#include <systemc.h>
#include <fstream>
#include "tester.h"
#include "counter.h"
using namespace std;

int sc_main(int argc, char *argv[]) {
    sc_signal <sc_uint<3> > mod_in, mod_out;
    sc_signal <bool> mod_enable, mod_load, mod_reset;
    sc_clock clk("clock", 10, SC_NS);

    CounterMod8 module_count("adder");
    module_count.in(mod_in);
    module_count.out(mod_out);
    module_count.clk(clk);
    module_count.enable(mod_enable);
    module_count.load(mod_load);
    module_count.reset(mod_reset);

    Tester testbench("testbench");
    testbench.clk(clk);
    testbench.data(mod_in);
    testbench.enable(mod_enable);
    testbench.load(mod_load);
    testbench.reset(mod_reset);

    sc_trace_file *t_file = sc_create_vcd_trace_file("test");
    sc_trace(t_file, clk, "clock");
    sc_trace(t_file, mod_in, "data_in");
    sc_trace(t_file, mod_out, "data_out");
    sc_trace(t_file, mod_enable, "enable");
    sc_trace(t_file, mod_load, "load");
    sc_trace(t_file, mod_reset, "reset");

    sc_start();
}
