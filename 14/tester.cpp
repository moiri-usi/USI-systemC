#include "systemc.h"
#include "tester.h"
#include <iostream>
#include <fstream>

void Tester::testing() {
    bool t_a, t_b;

    wait();
    while(1) {
        if (infile >> t_a >> t_b) {
            out1.write(t_a);
            out2.write(t_b);
            wait();
        }
        else {
            break;
        }
    }
    sc_stop();
}
