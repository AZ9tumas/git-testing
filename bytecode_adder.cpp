#include "bytecode_interpreter.h"

int main() {
    // Example: Add 5 + 3
    std::vector<int> program1 = {
        PUSH, 5,
        PUSH, 3,
        ADD,
        HALT
    };
    
    BytecodeInterpreter interp1(program1);
    std::cout << "5 + 3 = " << interp1.execute() << std::endl;
    
    // Example: Add 10 + 20 + 30
    std::vector<int> program2 = {
        PUSH, 10,
        PUSH, 20,
        ADD,
        PUSH, 30,
        ADD,
        HALT
    };
    
    BytecodeInterpreter interp2(program2);
    std::cout << "10 + 20 + 30 = " << interp2.execute() << std::endl;
    
    // Example: Add 100 + 200
    std::vector<int> program3 = {
        PUSH, 100,
        PUSH, 200,
        ADD,
        HALT
    };
    
    BytecodeInterpreter interp3(program3);
    std::cout << "100 + 200 = " << interp3.execute() << std::endl;
    
    return 0;
}
