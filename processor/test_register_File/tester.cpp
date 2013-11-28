#include "systemc.h"
#include "tester.h"
#include <iostream>
#include <fstream>

void tester::tester_func(){
  bool t_reset;
  unsigned int t_data,t_we;
  while(1){
    if (infile >> t_data >> t_we >> t_reset)
    {
      in.write(t_data);
      we.write(t_we);
      reset.write(t_reset);  
      wait();
    }
    else
      break;    
  }
  sc_stop();
}