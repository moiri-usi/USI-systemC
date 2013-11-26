#include <systemc.h>

SC_MODULE(reg1) {
    sc_in <bool> in;
    sc_in <bool> clk, reset, enable;
    sc_out <bool> out;

    void reg() {
        if (!reset.read()) {
            out.write(0);
        }
        else if (enable.read()) {
            out.write(in.read());
        }
    }

    SC_CTOR(reg1) {
        SC_METHOD(reg);
        sensitive << clk.pos() << reset.neg();
    }
};
