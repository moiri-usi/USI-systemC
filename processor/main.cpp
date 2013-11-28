#include <systemc.h>
#include <fstream>
#include "tester.h"
#include "processor.h"
using namespace std;

int sc_main(int argc, char *argv[]) {
    sc_signal <sc_uint<17> > mod_instruction;
    sc_signal <sc_uint<8> > mod_out;
    sc_signal <bool> mod_reset_n;
    sc_clock clk("clock", 10, SC_NS);

    Processor module_proc("processor");
    module_proc.clk(clk);
    module_proc.reset_n(mod_reset_n);
    module_proc.instruction(mod_instruction);
    module_proc.out(mod_out);

    Tester testbench("testbench");
    testbench.clk(clk);
    testbench.instruction(mod_instruction);
    testbench.reset_n(mod_reset_n);

    sc_trace_file *t_file = sc_create_vcd_trace_file("test");
    sc_trace(t_file, clk, "clock");
    sc_trace(t_file, mod_instruction, "instruction");
    sc_trace(t_file, mod_out, "output");
    sc_trace(t_file, mod_reset_n, "reset_n");

    sc_start();
}
