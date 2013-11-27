#include <systemc.h>
#include "shiftReg8.h"

void ShiftReg8::shifter() {
    if (!reset.read()) {
        reg = 0;
    }
    else if(enable.read()) {
        reg = reg<<1;
        reg[0] = in;
    }
    out.write(reg);
}
