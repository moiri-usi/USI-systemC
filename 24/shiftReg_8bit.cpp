#include "shiftReg_8bit.h"

void ShiftReg_8bit::shifter() {
    if (!reset_n.read()) {
        reg = 0;
    }
    else if(enable.read()) {
        reg = reg<<1;
        reg[0] = in;
    }
    out.write(reg);
}
