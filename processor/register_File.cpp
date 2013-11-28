#include <systemc.h>
#include "register_File.h"

void Register_File::regfile(){
    if(!reset_n.read())
    {
        data[0] = data[1] = data[2] = data[3] = 0;
    }
    else
    {
        for (int i=0; i<4;i++)
        {
            if(we_n.read()[i] == 0)
            {
                data[i] = data_in.read();
            }
        }
    }
    data_out1.write(data[0]);
    data_out2.write(data[1]);
    data_out3.write(data[2]);
    data_out4.write(data[3]);
}
