#include <systemc.h>
#include "parser.h"

void Parser::parse() {
    if (!reset.read()) {
        state = 0;
    }
    switch(state) {
        case 0:
            if (in.read()) state = 1;
            out.write(0);
            break;
        case 1:
            state = 0;
            if (in.read()) state = 2;
            out.write(0);
            break;
        case 2:
            if (!in.read()) state = 3;
            out.write(0);
            break;
        case 3:
            state = 1;
            if (!in.read()) state = 4;
            out.write(0);
            break;
        case 4:
            state = 0;
            if (in.read()) state = 5;
            out.write(0);
            break;
        case 5:
            state = 0;
            if (in.read()) state = 6;
            out.write(0);
            break;
        case 6:
            state = 2;
            if (!in.read()) state = 7;
            out.write(0);
            break;
        case 7:
            if (!in.read()) {
                state = 0;
                out.write(1);
            }
            else {
                state = 1;
                out.write(0);
            }
            break;
        default:
            state = 1;
            out.write(0);
    }
}
