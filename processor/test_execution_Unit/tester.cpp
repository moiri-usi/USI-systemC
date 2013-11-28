#include "systemc.h"
#include "tester.h"
#include <iostream>
#include <fstream>

void tester::tester_func(){
  unsigned int t_data1,t_data2,t_control;
  while(1){
    if (infile >> t_data1 >> t_data2 >> t_control)
    {
      out1.write(t_data1);
      out2.write(t_data2);
      ctrl.write(t_control);
      wait();
    }
    else
      break;    
  }
  sc_stop();
}