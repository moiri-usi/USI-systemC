#include <systemc.h>
#include "counter.h"

void CounterMod8::counter() {
    if (!reset.read()) {
        count = 0;
    }
    else if(enable.read()) {
        if (load.read()) {
            count = in;
        }
        else {
            count++;
        }
    }
    out.write(count);
}
