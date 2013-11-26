#include <systemc.h>
#include <fstream>
#include "and.h"
#include "or.h"
#include "xor.h"
#include "tester.h"
using namespace std;

int sc_main(int argc, char *argv[]) {
    sc_signal <bool> mod_in1, mod_in2;
    sc_signal <bool> and_out, or_out, xor_out;
    sc_clock clk("clock", 10, SC_NS);

    And2 module_and("and2");
    module_and.in1(mod_in1);
    module_and.in2(mod_in2);
    module_and.out(and_out);
    Or2 module_or("or2");
    module_or.in1(mod_in1);
    module_or.in2(mod_in2);
    module_or.out(or_out);
    Xor2 module_xor("xor2");
    module_xor.in1(mod_in1);
    module_xor.in2(mod_in2);
    module_xor.out(xor_out);

    Tester testbench("testbench1");
    testbench.clk(clk);
    testbench.and_in(and_out);
    testbench.or_in(or_out);
    testbench.xor_in(xor_out);
    testbench.out1(mod_in1);
    testbench.out2(mod_in2);

    sc_trace_file *t_file = sc_create_vcd_trace_file("test");
    sc_trace(t_file, clk, "clock");
    sc_trace(t_file, mod_in1, "a");
    sc_trace(t_file, mod_in2, "b");
    sc_trace(t_file, and_out, "and");
    sc_trace(t_file, or_out, "or");
    sc_trace(t_file, xor_out, "xor");

    sc_start();
}
