#include "systemc.h"
#include "tester.h"
#include <iostream>
#include <fstream>

void Tester::testing() {
    char t_instruction[20];

    wait();
    while(1) {
        if (infile >> t_instruction) {
            instruction.write(t_instruction);
            wait();
        }
        else {
            break;
        }
    }
    sc_stop();
}
