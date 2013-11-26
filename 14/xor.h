#include <systemc.h>

SC_MODULE(Xor2) {
    sc_in <bool> in1, in2;
    sc_out <bool> out;

    void xor2() {
        out.write(in1.read() ^ in2.read());
    }

    SC_CTOR(Xor2) {
        SC_METHOD(xor2);
        sensitive << in1 << in2;
    }
};
