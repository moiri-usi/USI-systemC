#include <systemc.h>

SC_MODULE(Execution_Unit) {
  sc_in<sc_uint<8> > data_in_a;
  sc_in<sc_uint<8> > data_in_b;
  sc_in<sc_bv<3> > ctrl;
  sc_out<sc_uint<8> > data_out;

  void execute();

  SC_CTOR(Execution_Unit) {
    SC_METHOD(execute);
    sensitive << data_in_a << data_in_b << ctrl;
  }

};
