#include <systemc.h>

SC_MODULE(tester) {
    sc_in <int> in1;
    sc_out <int> out1, out2;
    void testing() {
        int a = 5;
        int b = 78;
        out1.write(a);
        out2.write(b);
        wait(4, SC_NS);
        printf("%d + %d = %d", a, b, in1.read());
        if (in1.read() == a + b)
            printf(" -> PASSED\n");
        else
            printf(" -> FAILED\n");
        a = 51;
        b = 8;
        out1.write(a);
        out2.write(b);
        wait(4, SC_NS);
        printf("%d + %d = %d", a, b, in1.read());
        if (in1.read() == a + b)
            printf(" -> PASSED\n");
        else
            printf(" -> FAILED\n");
        a = 53;
        b = 41;
        out1.write(a);
        out2.write(b);
        wait(4, SC_NS);
        printf("%d + %d = %d", a, b, in1.read());
        if (in1.read() == a + b)
            printf(" -> PASSED\n");
        else
            printf(" -> FAILED\n");
    }

    SC_CTOR(tester) {
        SC_THREAD(testing);
        sensitive << in1;
    }
};
