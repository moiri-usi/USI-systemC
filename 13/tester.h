#include <systemc.h>

SC_MODULE(tester) {
    sc_in <bool> in;
    sc_in <bool> clk;
    sc_out <bool> out;
    sc_out <bool> reset_reg, enable_reg;
    void testing() {
        bool a = 1;
        out.write(a);
        reset_reg.write(1);
        enable_reg.write(1);
        wait(2);
        if (in.read() == a)
            printf(" -> PASSED\n");
        else
            printf(" -> FAILED\n");

        reset_reg.write(0);
        wait(2);
        if (in.read() == 0)
            printf(" -> PASSED\n");
        else
            printf(" -> FAILED\n");

        a = 1;
        reset_reg.write(1);
        out.write(a);
        wait(2);
        if (in.read() == a)
            printf(" -> PASSED\n");
        else
            printf(" -> FAILED\n");

        bool b = !a;
        enable_reg.write(0);
        out.write(b);
        wait(2);
        if (in.read() == a)
            printf(" -> PASSED\n");
        else
            printf(" -> FAILED\n");
        sc_stop();
    }

    SC_CTOR(tester) {
        SC_THREAD(testing);
        sensitive << clk.pos();
    }
};
