#include <systemc.h>
#include "register_17bit.h"
#include "register_8bit.h"
#include "register_File.h"
#include "mux_4to1_8bit.h"
#include "mux_2to1_8bit.h"
#include "decoder.h"
#include "controller.h"
#include "execution_Unit.h"

SC_MODULE(Processor) {
    sc_in <sc_uint<17> > instruction;
    sc_in <bool> clk, reset_n;
    sc_out <sc_uint<8> > out;
    sc_signal <sc_uint<17> > s_inst_r;
    sc_signal <sc_uint<8> > s_immediate, s_immediate_r,
              s_op1, s_op2, s_op1_int, s_op1_r, s_op2_r, s_op, s_op_r,
              s_op1_rf, s_op2_rf, s_op3_rf, s_op4_rf;
    sc_signal <sc_bv<4> > s_we_n;
    sc_signal <sc_uint<3> > s_opcode;
    sc_signal <sc_bv<3> > s_sel_op;
    sc_signal <sc_uint<2> > s_addr_in_1, s_addr_in_2, s_addr_out;
    sc_signal <sc_bv<2> > s_sel_in_1, s_sel_in_2;
    sc_signal <bool> s_sel_const;

    Register_17bit reg17;
    Register_8bit reg8_1;
    Register_8bit reg8_2;
    Register_8bit reg8_3;
    Register_8bit reg8_4;
    Mux_4to1_8bit mux_4to1_8_1;
    Mux_4to1_8bit mux_4to1_8_2;
    Mux_2to1_8bit mux_2to1_8;
    Decoder decoder;
    Controller controller;
    Register_File regF;
    Execution_Unit exe;

    void set_out() {
            out.write(s_op_r);
    }

    SC_CTOR(Processor): reg17("reg17"), reg8_1("reg8_1"), reg8_2("reg8_2"),
            reg8_3("reg8_3"), reg8_4("reg8_4"), mux_4to1_8_1("mux_4to1_8_1"),
            mux_4to1_8_2("mux_4to1_8_2"), mux_2to1_8("mux_2to1_8"),
            decoder("dec"), controller("ctrl"), regF("regF"), exe("exe") {

        reg17.clk(clk);
        reg17.reset_n(reset_n);
        reg17.in(instruction);
        reg17.out(s_inst_r);
        reg8_1.clk(clk);
        reg8_1.reset_n(reset_n);
        reg8_1.in(s_immediate);
        reg8_1.out(s_immediate_r);
        reg8_2.clk(clk);
        reg8_2.reset_n(reset_n);
        reg8_2.in(s_op1_int);
        reg8_2.out(s_op1_r);
        reg8_3.clk(clk);
        reg8_3.reset_n(reset_n);
        reg8_3.in(s_op);
        reg8_3.out(s_op_r);
        reg8_4.clk(clk);
        reg8_4.reset_n(reset_n);
        reg8_4.in(s_op2);
        reg8_4.out(s_op2_r);
        mux_4to1_8_1.in1(s_op1_rf);
        mux_4to1_8_1.in2(s_op2_rf);
        mux_4to1_8_1.in3(s_op3_rf);
        mux_4to1_8_1.in4(s_op4_rf);
        mux_4to1_8_1.select(s_sel_in_1);
        mux_4to1_8_1.out(s_op1);
        mux_4to1_8_2.in1(s_op1_rf);
        mux_4to1_8_2.in2(s_op2_rf);
        mux_4to1_8_2.in3(s_op3_rf);
        mux_4to1_8_2.in4(s_op4_rf);
        mux_4to1_8_2.select(s_sel_in_2);
        mux_4to1_8_2.out(s_op2);
        mux_2to1_8.in1(s_op1);
        mux_2to1_8.in2(s_immediate_r);
        mux_2to1_8.select(s_sel_const);
        mux_2to1_8.out(s_op1_int);
        decoder.instruction(s_inst_r);
        decoder.immediate(s_immediate);
        decoder.opcode(s_opcode);
        decoder.addr_in_1(s_addr_in_1);
        decoder.addr_in_2(s_addr_in_2);
        decoder.addr_out(s_addr_out);
        controller.clk(clk);
        controller.reset_n(reset_n);
        controller.opcode(s_opcode);
        controller.addr_in_1(s_addr_in_1);
        controller.addr_in_2(s_addr_in_2);
        controller.addr_out(s_addr_out);
        controller.we_n(s_we_n);
        controller.sel_in_1(s_sel_in_1);
        controller.sel_in_2(s_sel_in_2);
        controller.sel_op(s_sel_op);
        controller.sel_const(s_sel_const);
        regF.clk(clk);
        regF.reset_n(reset_n);
        regF.we_n(s_we_n);
        regF.data_in(s_op_r);
        regF.data_out1(s_op1_rf);
        regF.data_out2(s_op2_rf);
        regF.data_out3(s_op3_rf);
        regF.data_out4(s_op4_rf);
        exe.ctrl(s_sel_op);
        exe.data_in_a(s_op1_r);
        exe.data_in_b(s_op2_r);
        exe.data_out(s_op);
        SC_METHOD(set_out);
        sensitive << s_op_r;
    }
};
