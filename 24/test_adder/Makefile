OBJS = main.o tester.o
G++ = g++
SYSTEMC_DIR = /opt/systemc-2.3.0
I_DIR = -I ./ -I ../ -I $(SYSTEMC_DIR)/include
L_DIR = -L $(SYSTEMC_DIR)/lib-linux64
LIB = -lsystemc
test: $(OBJS)
	$(G++) $(I_DIR) $(L_DIR) -o $@ $(OBJS) $(LIB)
.cpp.o:
	$(G++) $(I_DIR) -c -o $@ $<
clean:
	rm -f test
	rm -f *.o
	rm -f *.vcd
