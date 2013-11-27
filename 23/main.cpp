#include <systemc.h>
#include <fstream>
#include "tester.h"
#include "parser.h"
using namespace std;

int sc_main(int argc, char *argv[]) {
    sc_signal <bool> mod_out, mod_in, mod_reset;
    sc_clock clk("clock", 10, SC_NS);

    Parser module_parser("parser");
    module_parser.in(mod_in);
    module_parser.reset(mod_reset);
    module_parser.out(mod_out);
    module_parser.clk(clk);

    Tester testbench("testbench");
    testbench.clk(clk);
    testbench.data(mod_in);
    testbench.reset(mod_reset);

    sc_trace_file *t_file = sc_create_vcd_trace_file("test");
    sc_trace(t_file, clk, "clock");
    sc_trace(t_file, mod_in, "data_in");
    sc_trace(t_file, mod_out, "data_out");
    sc_trace(t_file, mod_reset, "reset");

    sc_start();
}
