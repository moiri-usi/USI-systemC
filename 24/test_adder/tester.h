#include <systemc.h>
#include <fstream>
#include <iostream>

SC_MODULE(Tester) {
    sc_in <bool> clk;
    sc_out <bool> add_cin, add_enable;
    sc_out <sc_uint<8> > add_in1, add_in2;
    ifstream infile;

    void testing();

    SC_CTOR(Tester) {
        SC_THREAD(testing);
        sensitive << clk.pos();
        infile.open("usr.in");
    }
};
