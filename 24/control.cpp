#include "control.h"

void Controller::sm() {
    if (!reset_n.read()) {
        stall = STALL;
        state = STATE_SHIFT_OP1;
        add_enable.write(0);
        reg_enable.write(0);
        shiftReg_enable.write(0);
    }
    switch(state) {
        case STATE_SHIFT_OP1:
            if (cnt_overflow.read()) state = STATE_SHIFT_OP2;
            add_enable.write(0);
            reg_enable.write(1);
            shiftReg_enable.write(1);
            break;
        case STATE_SHIFT_OP2:
            if (cnt_overflow.read()) state = STATE_ADD;
            add_enable.write(0);
            reg_enable.write(0);
            shiftReg_enable.write(1);
            break;
        case STATE_ADD:
            if (stall == 0) {
                state = STATE_SHIFT_OP1;
                stall = STALL;
            }
            add_enable.write(1);
            reg_enable.write(0);
            shiftReg_enable.write(0);
            stall--;
            break;
        default:
            state = STATE_SHIFT_OP1;
            add_enable.write(0);
            reg_enable.write(0);
            shiftReg_enable.write(0);
    }
}
