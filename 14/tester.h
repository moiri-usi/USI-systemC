#include <systemc.h>
#include <fstream>
#include <iostream>

SC_MODULE(Tester) {
    sc_in <bool> and_in, or_in, xor_in;
    sc_in <bool> clk;
    sc_out <bool> out1, out2;
    ifstream infile;

    void testing();

    SC_CTOR(Tester) {
        SC_THREAD(testing);
        sensitive << clk.pos();
        infile.open("usr.in");
    }
};
