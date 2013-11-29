#include "counter.h"

void CounterMod8::counter() {
    if (!reset_n.read()) {
        count = 0;
        overflow.write(0);
    }
    else {
        count++;
        if (count == 0) {
            overflow.write(1);
        }
        else {
            overflow.write(0);
        }
    }
}
