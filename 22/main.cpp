#include <systemc.h>
#include <fstream>
#include "tester.h"
#include "shiftReg8.h"
using namespace std;

int sc_main(int argc, char *argv[]) {
    sc_signal <sc_uint<8> > mod_out;
    sc_signal <bool> mod_enable, mod_reset, mod_in;
    sc_clock clk("clock", 10, SC_NS);

    ShiftReg8 module_shift("shifter");
    module_shift.in(mod_in);
    module_shift.out(mod_out);
    module_shift.clk(clk);
    module_shift.enable(mod_enable);
    module_shift.reset(mod_reset);

    Tester testbench("testbench");
    testbench.clk(clk);
    testbench.data(mod_in);
    testbench.enable(mod_enable);
    testbench.reset(mod_reset);

    sc_trace_file *t_file = sc_create_vcd_trace_file("test");
    sc_trace(t_file, clk, "clock");
    sc_trace(t_file, mod_in, "data_in");
    sc_trace(t_file, mod_out, "data_out");
    sc_trace(t_file, mod_enable, "enable");
    sc_trace(t_file, mod_reset, "reset");

    sc_start();
}
