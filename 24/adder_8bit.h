#include <systemc.h>
#include "adder_1bit.h"

SC_MODULE(Adder_8bit) {
    sc_in <bool> cin, enable, reset_n;
    sc_in <sc_uint<8> > in1, in2;
    sc_out <bool> cout;
    sc_out <sc_uint<8> > out;
    sc_signal <bool> add1_in1, add2_in1, add3_in1, add4_in1;
    sc_signal <bool> add5_in1, add6_in1, add7_in1, add8_in1;
    sc_signal <bool> add1_in2, add2_in2, add3_in2, add4_in2;
    sc_signal <bool> add5_in2, add6_in2, add7_in2, add8_in2;
    sc_signal <bool> add1_cin;
    sc_signal <bool> add1_out, add2_out, add3_out, add4_out;
    sc_signal <bool> add5_out, add6_out, add7_out, add8_out;
    sc_signal <bool> add1_cout, add2_cout, add3_cout, add4_cout;
    sc_signal <bool> add5_cout, add6_cout, add7_cout, add8_cout;
    Adder1 module_add1;
    Adder1 module_add2;
    Adder1 module_add3;
    Adder1 module_add4;
    Adder1 module_add5;
    Adder1 module_add6;
    Adder1 module_add7;
    Adder1 module_add8;

    void selector() {
        //sc_bv<8> temp_out = static_cast<sc_bv<8> >(out.read());
        sc_bv<8> temp_out;
        if (!reset_n.read()) {
            out.write(static_cast<sc_uint<8> >("0b00000000"));
            cout.write(0); // do this here to keep cout in sync
        }
        else {
            if (enable.read()) {
                add1_in1.write(in1.read()[0]);
                add2_in1.write(in1.read()[1]);
                add3_in1.write(in1.read()[2]);
                add4_in1.write(in1.read()[3]);
                add5_in1.write(in1.read()[4]);
                add6_in1.write(in1.read()[5]);
                add7_in1.write(in1.read()[6]);
                add8_in1.write(in1.read()[7]);
                add1_in2.write(in2.read()[0]);
                add2_in2.write(in2.read()[1]);
                add3_in2.write(in2.read()[2]);
                add4_in2.write(in2.read()[3]);
                add5_in2.write(in2.read()[4]);
                add6_in2.write(in2.read()[5]);
                add7_in2.write(in2.read()[6]);
                add8_in2.write(in2.read()[7]);
                temp_out[0] = add1_out.read();
                temp_out[1] = add2_out.read();
                temp_out[2] = add3_out.read();
                temp_out[3] = add4_out.read();
                temp_out[4] = add5_out.read();
                temp_out[5] = add6_out.read();
                temp_out[6] = add7_out.read();
                temp_out[7] = add8_out.read();
            }
            out.write(static_cast<sc_uint<8> >(temp_out));
            cout.write(add8_cout); // do this here to keep cout in sync
        }
    }

    SC_CTOR(Adder_8bit): module_add1("add1"), module_add2("add2"),
            module_add3("add3"), module_add4("add4"),
            module_add5("add5"), module_add6("add6"),
            module_add7("add7"), module_add8("add8") {
        SC_METHOD(selector);
        sensitive << in1 << in2 << cin << enable;
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
        module_add5.in1(add5_in1);
        module_add5.in2(add5_in2);
        module_add5.cin(add4_cout);
        module_add5.out(add5_out);
        module_add5.cout(add5_cout);
        module_add6.in1(add6_in1);
        module_add6.in2(add6_in2);
        module_add6.cin(add5_cout);
        module_add6.out(add6_out);
        module_add6.cout(add6_cout);
        module_add7.in1(add7_in1);
        module_add7.in2(add7_in2);
        module_add7.cin(add6_cout);
        module_add7.out(add7_out);
        module_add7.cout(add7_cout);
        module_add8.in1(add8_in1);
        module_add8.in2(add8_in2);
        module_add8.cin(add7_cout);
        module_add8.out(add8_out);
        module_add8.cout(add8_cout);
    }
};
