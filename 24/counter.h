#include <systemc.h>

SC_MODULE(CounterMod8) {
    sc_in <bool> reset_n, clk;
    sc_out <bool> overflow;
    sc_uint<3> count;

    void counter();

    SC_CTOR(CounterMod8) {
        SC_METHOD(counter);
        sensitive << clk.pos() << reset_n.neg();
        count = 0;
    }
};
