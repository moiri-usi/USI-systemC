#include "systemc.h"
#include "tester.h"
#include <iostream>
#include <fstream>

void Tester::testing() {
    bool t_enable, t_reset;
    bool t_data;

    while(1) {
        if (infile >> t_enable >> t_reset >> t_data) {
            wait();
            out.write(t_data);
            enable_reg.write(t_enable);
            reset_reg.write(t_reset);
        }
        else {
            break;
        }
    }
    sc_stop();
}
