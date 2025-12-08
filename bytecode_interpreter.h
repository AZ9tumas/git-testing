#ifndef BYTECODE_INTERPRETER_H
#define BYTECODE_INTERPRETER_H

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
            int opcode = bytecode[pc++];
            
            // Validate opcode
            if (opcode < PUSH || opcode > HALT) {
                std::cerr << "Error: Invalid opcode " << opcode << std::endl;
                return 0;
            }
            
            OpCode op = static_cast<OpCode>(opcode);
            
            switch (op) {
                case PUSH:
                    if (pc < bytecode.size()) {
                        stack.push(bytecode[pc++]);
                    } else {
                        std::cerr << "Error: PUSH missing operand" << std::endl;
                        return 0;
                    }
                    break;
                    
                case ADD:
                    if (stack.size() >= 2) {
                        int b = stack.top(); stack.pop();
                        int a = stack.top(); stack.pop();
                        stack.push(a + b);
                    } else {
                        std::cerr << "Error: ADD requires 2 values on stack" << std::endl;
                        return 0;
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

#endif // BYTECODE_INTERPRETER_H
