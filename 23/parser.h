#include <systemc.h>

SC_MODULE(Parser) {
    sc_in <bool> clk, in, reset;
    sc_out <bool> out;
    sc_uint<3> state;

    void parse();

    SC_CTOR(Parser) {
        SC_METHOD(parse);
        sensitive << clk.pos() << reset.neg();
        state = 0;
    }
};
