#include <systemc.h>

#define STATE_SHIFT_OP1 0
#define STATE_SHIFT_OP2 1
#define STATE_ADD 2
#define STALL 3

SC_MODULE(Controller) {
    sc_in <bool> clk, cnt_overflow, reset_n;
    sc_out <bool> shiftReg_enable, reg_enable, add_enable;
    sc_uint<2> state;
    sc_uint<2> stall;

    void sm();

    SC_CTOR(Controller) {
        SC_METHOD(sm);
        sensitive << clk.pos() << reset_n.neg();
        state = 0;
        stall = STALL;
    }
};
