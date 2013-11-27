#include <systemc.h>

SC_MODULE(Or2) {
    sc_in <bool> in1, in2;
    sc_out <bool> out;

    void or2() {
        out.write(in1.read() | in2.read());
    }

    SC_CTOR(Or2) {
        SC_METHOD(or2);
        sensitive << in1 << in2;
    }
};
