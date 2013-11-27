#include <systemc.h>
#include "adder1.h"

SC_MODULE(Adder4) {
    sc_in <bool> cin;
    sc_in <sc_uint<4> > in1, in2;
    sc_out <bool> cout;
    sc_out <sc_uint<4> > out;
    sc_signal <bool> add1_in1, add2_in1, add3_in1, add4_in1;
    sc_signal <bool> add1_in2, add2_in2, add3_in2, add4_in2;
    sc_signal <bool> add1_cin;
    sc_signal <bool> add1_out, add2_out, add3_out, add4_out;
    sc_signal <bool> add1_cout, add2_cout, add3_cout, add4_cout;
    Adder1 module_add1;
    Adder1 module_add2;
    Adder1 module_add3;
    Adder1 module_add4;

    void selector() {
        sc_lv<4> temp_out;
        add1_in1.write(in1.read()[0]);
        add2_in1.write(in1.read()[1]);
        add3_in1.write(in1.read()[2]);
        add4_in1.write(in1.read()[3]);
        add1_in2.write(in2.read()[0]);
        add2_in2.write(in2.read()[1]);
        add3_in2.write(in2.read()[2]);
        add4_in2.write(in2.read()[3]);
        temp_out[0] = add1_out.read();
        temp_out[1] = add2_out.read();
        temp_out[2] = add3_out.read();
        temp_out[3] = add4_out.read();
        out = temp_out;
        cout.write(add4_cout); // do this here to keep cout in sync
    }

    SC_CTOR(Adder4): module_add1("add1"), module_add2("add2"),
            module_add3("add3"), module_add4("add4") {
        SC_METHOD(selector);
        sensitive << in1 << in2 << cin;
        module_add1.in1(add1_in1);
        module_add1.in2(add1_in2);
        module_add1.cin(cin);
        module_add1.out(add1_out);
        module_add1.cout(add1_cout);
        module_add2.in1(add2_in1);
        module_add2.in2(add2_in2);
        module_add2.cin(add1_cout);
        module_add2.out(add2_out);
        module_add2.cout(add2_cout);
        module_add3.in1(add3_in1);
        module_add3.in2(add3_in2);
        module_add3.cin(add2_cout);
        module_add3.out(add3_out);
        module_add3.cout(add3_cout);
        module_add4.in1(add4_in1);
        module_add4.in2(add4_in2);
        module_add4.cin(add3_cout);
        module_add4.out(add4_out);
        module_add4.cout(add4_cout);
    }
};
