#include <systemc.h>
#include <fstream>
#include "reg1.h"
#include "tester.h"
using namespace std;

int sc_main(int argc, char *argv[]) {
    sc_signal <bool> mod_in, mod_out;
    sc_signal <bool> reset, enable;
    sc_clock clk("clock", 10, SC_NS);

    reg1 module_reg("reg1");
    module_reg.enable(enable);
    module_reg.reset(reset);
    module_reg.in(mod_in);
    module_reg.clk(clk);
    module_reg.out(mod_out);

    Tester testbench("testbench1");
    testbench.out(mod_in);
    testbench.clk(clk);
    testbench.enable_reg(enable);
    testbench.reset_reg(reset);

    sc_trace_file *t_file = sc_create_vcd_trace_file("test");
    sc_trace(t_file, clk, "clock");
    sc_trace(t_file, enable, "enable");
    sc_trace(t_file, reset, "reset");
    sc_trace(t_file, mod_in, "reg_in");
    sc_trace(t_file, mod_out, "reg_out");

    sc_start();
}
