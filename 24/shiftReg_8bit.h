#include <systemc.h>

SC_MODULE(ShiftReg_8bit) {
    sc_in <bool> enable, reset_n, clk, in;
    sc_out <sc_uint<8> > out;
    sc_uint<8> reg;

    void shifter();

    SC_CTOR(ShiftReg_8bit) {
        SC_METHOD(shifter);
        sensitive << clk.pos() << reset_n.neg();
    }
};
