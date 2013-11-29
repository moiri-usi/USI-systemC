#include "systemc.h"
#include "tester.h"
#include <iostream>
#include <fstream>

void Tester::testing() {
    unsigned int t_a, t_b;
    bool t_cin, t_enable;

    wait();
    while(1) {
        if (infile >> t_a >> t_b >> t_cin >> t_enable) {
            add_in1.write(t_a);
            add_in2.write(t_b);
            add_cin.write(t_cin);
            add_enable.write(t_enable);
            wait();
        }
        else {
            break;
        }
    }
    sc_stop();
}
