#include <systemc.h>
#include <fstream>
#include <iostream>

SC_MODULE ( tester ){
  sc_in <bool> clk ; 
  sc_in <sc_uint <8> > out3;
  sc_out <sc_uint <8> > out1, out2 ;
  sc_out <sc_bv <3> >  ctrl;
  
  ifstream infile;
  void tester_func ();
    SC_CTOR( tester ){
    SC_THREAD( tester_func ) ;
    sensitive << clk.pos( ) ;
    infile.open("usr.in") ;
  }
};