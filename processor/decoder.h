#include <systemc.h>

SC_MODULE(Decoder) {
    sc_in <sc_uint<17> > instruction;
    sc_out <sc_uint<8> > immediate;
    sc_out <sc_uint<3> > opcode;
    sc_out <sc_uint<2> > addr_in_1, addr_in_2, addr_out;
    sc_uint<3> state;

    void decode();

    SC_CTOR(Decoder) {
        SC_METHOD(decode);
        sensitive << instruction;
    }
};
