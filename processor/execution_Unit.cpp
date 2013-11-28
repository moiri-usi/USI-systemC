#include "execution_Unit.h"

void Execution_Unit::execute(){
    int result;
    switch ((ctrl.read()).to_uint())
    {
        case 1: result = data_in_a.read(); break;
        case 2: result = data_in_a.read() + data_in_b.read(); break;
        case 3: result = data_in_a.read() | data_in_b.read(); break;
        case 4: result = data_in_a.read() & data_in_b.read(); break;
        case 5: result = data_in_a.read() << 1; break;
                // case "000": result = 0; break;
        default: result = 0; break;
    }
    data_out.write(result);
}
