#include "tester.h"

void Tester::testing() {
    bool t_data, t_reset_n;

    wait();
    while(1) {
        if (infile >> t_data >> t_reset_n) {
            data.write(t_data);
            reset_n.write(t_reset_n);
            wait();
        }
        else {
            break;
        }
    }
    sc_stop();
}
