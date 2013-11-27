#include "systemc.h"
#include "tester.h"
#include <iostream>
#include <fstream>

void Tester::testing() {
    unsigned int t_data;
    bool t_enable, t_load, t_reset;

    wait();
    while(1) {
        if (infile >> t_data >> t_enable >> t_reset) {
            data.write(t_data);
            enable.write(t_enable);
            reset.write(t_reset);
            wait();
        }
        else {
            break;
        }
    }
    sc_stop();
}
