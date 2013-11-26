#include <systemc.h>

SC_MODULE(simple_adder) {
    sc_in <int> in1;
    sc_in <int> in2;
    sc_out <int> out1;

    void sum() {
        out1.write(in1.read() + in2.read());
    }

    SC_CTOR(simple_adder) {
        SC_METHOD(sum);
        sensitive << in1 << in2;
    }
};
