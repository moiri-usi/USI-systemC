#include "systemc.h"
#include "tester.h"
#include <iostream>
#include <fstream>

void Tester::testing() {
    char t_instruction[20];
    bool t_reset_n;

    wait();
    while(1) {
        if (infile >> t_instruction >> t_reset_n) {
            instruction.write(t_instruction);
            reset_n.write(t_reset_n);
            wait();
        }
        else {
            break;
        }
    }
    sc_stop();
}
