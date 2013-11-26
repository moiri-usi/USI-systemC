#include <systemc.h>
#include <fstream>
#include <iostream>

SC_MODULE(Tester) {
    sc_in <bool> in;
    sc_in <bool> clk;
    sc_out <bool> out;
    sc_out <bool> reset_reg, enable_reg;
    ifstream infile;

    void testing();

    SC_CTOR(Tester) {
        SC_THREAD(testing);
        sensitive << clk.pos();
        infile.open("usr.in");
    }
};
