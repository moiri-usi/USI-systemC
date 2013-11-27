#include "systemc.h"
#include "tester.h"
#include <iostream>
#include <fstream>

void Tester::testing() {
    bool t_data, t_reset;

    wait();
    while(1) {
        if (infile >> t_data >> t_reset) {
            data.write(t_data);
            reset.write(t_reset);
            wait();
        }
        else {
            break;
        }
    }
    sc_stop();
}
