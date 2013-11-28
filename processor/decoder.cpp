#include <decoder.h>

void Decoder::decode() {
    opcode.write(instruction.read().range(16,14));
    immediate.write(instruction.read().range(13,6));
    addr_in_1.write(instruction.read().range(5,4));
    addr_in_2.write(instruction.read().range(3,2));
    addr_out.write(instruction.read().range(1,0));
}
