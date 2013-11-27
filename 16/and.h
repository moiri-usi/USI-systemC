#include <systemc.h>

SC_MODULE(And2) {
    sc_in <bool> in1, in2;
    sc_out <bool> out;

    void and2() {
        out.write(in1.read() & in2.read());
    }

    SC_CTOR(And2) {
        SC_METHOD(and2);
        sensitive << in1 << in2;
    }
};
