#include <systemc.h>

SC_MODULE(ShiftReg8) {
    sc_in <bool> enable, reset, clk, in;
    sc_out <sc_uint<8> > out;
    sc_uint<8> reg;

    void shifter();

    SC_CTOR(ShiftReg8) {
        SC_METHOD(shifter);
        sensitive << clk.pos() << reset.neg();
    }
};
