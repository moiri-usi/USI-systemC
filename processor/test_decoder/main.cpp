#include <systemc.h>
#include <fstream>
#include "tester.h"
#include "decoder.h"
using namespace std;

int sc_main(int argc, char *argv[]) {
    sc_signal <sc_uint<17> > mod_instruction;
    sc_signal <sc_uint<8> > mod_immediate;
    sc_signal <sc_uint<3> > mod_opcode;
    sc_signal <sc_uint<2> > mod_addr_in_1, mod_addr_in_2, mod_addr_out;
    sc_clock clk("clock", 10, SC_NS);

    Decoder module_decoder("decoder");
    module_decoder.instruction(mod_instruction);
    module_decoder.immediate(mod_immediate);
    module_decoder.opcode(mod_opcode);
    module_decoder.addr_in_1(mod_addr_in_1);
    module_decoder.addr_in_2(mod_addr_in_2);
    module_decoder.addr_out(mod_addr_out);

    Tester testbench("testbench");
    testbench.clk(clk);
    testbench.instruction(mod_instruction);

    sc_trace_file *t_file = sc_create_vcd_trace_file("test");
    sc_trace(t_file, clk, "clock");
    sc_trace(t_file, mod_instruction, "instruction");
    sc_trace(t_file, mod_immediate, "immediate");
    sc_trace(t_file, mod_opcode, "opcode");
    sc_trace(t_file, mod_addr_in_1, "addr_in_1");
    sc_trace(t_file, mod_addr_in_2, "addr_in_2");
    sc_trace(t_file, mod_addr_out, "addr_out");

    sc_start();
}
