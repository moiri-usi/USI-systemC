#include <systemc.h>
#include <fstream>
#include <iostream>

SC_MODULE(Tester) {
    sc_in <bool> clk;
    sc_in <bool> add_cout;
    sc_in <sc_uint<4> > add_out;
    sc_out <bool> add_cin;
    sc_out <sc_uint<4> > add_in1, add_in2;
    ifstream infile;

    void testing();

    SC_CTOR(Tester) {
        SC_THREAD(testing);
        sensitive << clk.pos();
        infile.open("usr.in");
    }
};
