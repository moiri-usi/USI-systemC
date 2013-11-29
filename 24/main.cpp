#include <systemc.h>
#include <fstream>
#include "tester.h"
#include "adder_8bit.h"
#include "register_8bit.h"
#include "shiftReg_8bit.h"
#include "counter.h"
#include "control.h"
using namespace std;

int sc_main(int argc, char *argv[]) {
    sc_signal <bool> cin, in, cout, reset_n, s_shiftReg_en, s_reg_en, s_add_en,
              s_overflow;
    sc_signal <sc_uint<8> > s_op_sr, s_op_r, out;
    sc_clock clk("clock", 10, SC_NS);

    Adder_8bit module_adder("adder");
    module_adder.reset_n(reset_n);
    module_adder.enable(s_add_en);
    module_adder.cin(cin);
    module_adder.in1(s_op_r);
    module_adder.in2(s_op_sr);
    module_adder.out(out);
    module_adder.cout(cout);

    Register_8bit module_reg8("reg8");
    module_reg8.clk(clk);
    module_reg8.reset_n(reset_n);
    module_reg8.enable(s_reg_en);
    module_reg8.in(s_op_sr);
    module_reg8.out(s_op_r);

    ShiftReg_8bit module_sReg8("sReg8");
    module_sReg8.clk(clk);
    module_sReg8.reset_n(reset_n);
    module_sReg8.enable(s_shiftReg_en);
    module_sReg8.in(in);
    module_sReg8.out(s_op_sr);

    CounterMod8 module_cnt("cnt");
    module_cnt.clk(clk);
    module_cnt.reset_n(reset_n);
    module_cnt.overflow(s_overflow);

    Controller module_ctrl("ctrl");
    module_ctrl.clk(clk);
    module_ctrl.reset_n(reset_n);
    module_ctrl.cnt_overflow(s_overflow);
    module_ctrl.shiftReg_enable(s_shiftReg_en);
    module_ctrl.reg_enable(s_reg_en);
    module_ctrl.add_enable(s_add_en);

    Tester testbench("testbench");
    testbench.clk(clk);
    testbench.data(in);
    testbench.reset_n(reset_n);

    sc_trace_file *t_file = sc_create_vcd_trace_file("test");
    sc_trace(t_file, clk, "clock");
    sc_trace(t_file, in, "in");
    sc_trace(t_file, s_op_sr, "s_op_sr");
    sc_trace(t_file, s_op_r, "s_op_r");
    sc_trace(t_file, s_shiftReg_en, "s_shiftReg_en");
    sc_trace(t_file, s_reg_en, "s_reg_en");
    sc_trace(t_file, module_adder.in1, "in1");
    sc_trace(t_file, s_add_en, "s_add_en");
    sc_trace(t_file, module_adder.in2, "in2");
    sc_trace(t_file, s_overflow, "s_overflow");
    sc_trace(t_file, out, "out");
    sc_trace(t_file, cout, "cout");
    sc_trace(t_file, reset_n, "reset_n");

    sc_start();
}
