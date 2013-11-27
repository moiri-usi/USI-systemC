#include <systemc.h>
#include "and.h"
#include "or.h"
#include "xor.h"

SC_MODULE(Adder1) {
    sc_in <bool> in1, in2, cin;
    sc_out <bool> out, cout;
    sc_signal <bool> xor1_out, and1_out, and2_out;
    Xor2 module_xor1;
    Xor2 module_xor2;
    And2 module_and1;
    And2 module_and2;
    Or2 module_or1;

    SC_CTOR(Adder1): module_xor1("xor1"), module_xor2("xor2"),
            module_and1("and1"), module_and2("and2"), module_or1("or1") {
        module_xor1.in1(in1);
        module_xor1.in2(in2);
        module_xor1.out(xor1_out);
        module_xor2.in1(xor1_out);
        module_xor2.in2(cin);
        module_xor2.out(out);
        module_and1.in1(xor1_out);
        module_and1.in2(cin);
        module_and1.out(and1_out);
        module_and2.in1(in1);
        module_and2.in2(in2);
        module_and2.out(and2_out);
        module_or1.in1(and1_out);
        module_or1.in2(and2_out);
        module_or1.out(cout);
    }
};
