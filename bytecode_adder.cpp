#include <iostream>
#include <vector>
#include <stack>

// Bytecode instructions
enum OpCode {
    PUSH,   // Push a value onto the stack
    ADD,    // Pop two values, add them, push result
    HALT    // Stop execution
};

// Simple bytecode interpreter
class BytecodeInterpreter {
private:
    std::stack<int> stack;
    std::vector<int> bytecode;
    size_t pc; // program counter

public:
    BytecodeInterpreter(const std::vector<int>& code) 
        : bytecode(code), pc(0) {}

    int execute() {
        while (pc < bytecode.size()) {
            OpCode op = static_cast<OpCode>(bytecode[pc++]);
            
            switch (op) {
                case PUSH:
                    if (pc < bytecode.size()) {
                        stack.push(bytecode[pc++]);
                    }
                    break;
                    
                case ADD:
                    if (stack.size() >= 2) {
                        int b = stack.top(); stack.pop();
                        int a = stack.top(); stack.pop();
                        stack.push(a + b);
                    }
                    break;
                    
                case HALT:
                    if (!stack.empty()) {
                        return stack.top();
                    }
                    return 0;
            }
        }
        
        if (!stack.empty()) {
            return stack.top();
        }
        return 0;
    }
};

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
