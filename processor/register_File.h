#include <systemc.h>

SC_MODULE(Register_File){
  sc_in<sc_uint<8> > data_in;
  sc_in<sc_bv<4> > we_n;
  sc_in<bool> reset_n;
  sc_in<bool> clk;
  sc_out<sc_uint<8> > data_out1, data_out2, data_out3, data_out4;
  unsigned int data[4];

  void regfile();

  SC_CTOR(Register_File){
    SC_METHOD(regfile);
    sensitive << clk.pos() << reset_n.neg();
  }

};
