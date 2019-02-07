CFLAGS = -O -Wall
CC = g++ -std=c++11
SRC = asm_interpreter.cpp ALI/ALI.cpp ALI/SAL/SAL.cpp ALI/CPU/ALI_CPU.cpp ALI/SAL/SAL_DEC.cpp ALI/SAL/SAL_LDA.cpp ALI/SAL/SAL_LDB.cpp ALI/SAL/SAL_LDI.cpp ALI/SAL/SAL_ST.cpp ALI/SAL/SAL_XCH.cpp ALI/SAL/SAL_JMP.cpp ALI/SAL/SAL_JZS.cpp ALI/SAL/SAL_JVS.cpp ALI/SAL/SAL_ADD.cpp ALI/SAL/SAL_HLT.cpp ALI/SAL/SAL_VALUE.cpp
OBJ = $(SRC:.cpp = .o)
compile: $(OBJ)
	$(CC) $(CFLAGS) -o asm_interpreter $(OBJ)
run:
	clear
	./asm_interpreter
clean:
	rm asm_interpreter
