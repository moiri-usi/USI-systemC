#include <systemc.h>
#include <simple_adder.h>
#include <tester.h>
using namespace std;

int sc_main(int argc, char *argv[]) {
    sc_signal <int> mod_in1, mod_in2, mod_out1;
    simple_adder module_adder("adder1");
    module_adder.in1(mod_in1);
    module_adder.in2(mod_in2);
    module_adder.out1(mod_out1);
    tester testbench("testbench1");
    testbench.out1(mod_in1);
    testbench.out2(mod_in2);
    testbench.in1(mod_out1);
    sc_start();
}
