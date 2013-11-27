#include <systemc.h>

SC_MODULE(CounterMod8) {
    sc_in <bool> enable, load, reset, clk;
    sc_in <sc_uint<3> > in;
    sc_out <sc_uint<3> > out;
    sc_uint<3> count;

    void counter();

    SC_CTOR(CounterMod8) {
        SC_METHOD(counter);
        sensitive << clk.pos() << reset.neg();
    }
};
