#include <systemc.h>
#include <reg1.h>
#include <tester.h>
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
    tester testbench("testbench1");
    testbench.out(mod_in);
    testbench.in(mod_out);
    testbench.clk(clk);
    testbench.enable_reg(enable);
    testbench.reset_reg(reset);
    sc_start();
}
