#include "bytecode_interpreter.h"
#include <cassert>
#include <iostream>
#include <sstream>

// Helper function to capture stderr and execute a test
int execute_with_stderr_capture(BytecodeInterpreter& interp) {
    std::streambuf* old_cerr = std::cerr.rdbuf();
    std::stringstream captured_cerr;
    std::cerr.rdbuf(captured_cerr.rdbuf());
    
    int result = interp.execute();
    
    std::cerr.rdbuf(old_cerr);
    return result;
}

void test_empty_program() {
    std::vector<int> program = {};
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 0);
    std::cout << "✓ test_empty_program passed" << std::endl;
}

void test_halt_only() {
    std::vector<int> program = {HALT};
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 0);
    std::cout << "✓ test_halt_only passed" << std::endl;
}

void test_push_without_halt() {
    std::vector<int> program = {PUSH, 100};
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 100);  // Should return top of stack
    std::cout << "✓ test_push_without_halt passed" << std::endl;
}

void test_add_without_halt() {
    std::vector<int> program = {PUSH, 10, PUSH, 20, ADD};
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 30);  // Should return top of stack
    std::cout << "✓ test_add_without_halt passed" << std::endl;
}

void test_invalid_opcode() {
    std::vector<int> program = {99, HALT};  // 99 is invalid opcode
    BytecodeInterpreter interp(program);
    int result = execute_with_stderr_capture(interp);
    assert(result == 0);
    std::cout << "✓ test_invalid_opcode passed" << std::endl;
}

void test_push_missing_operand() {
    std::vector<int> program = {PUSH};  // PUSH without operand
    BytecodeInterpreter interp(program);
    int result = execute_with_stderr_capture(interp);
    assert(result == 0);
    std::cout << "✓ test_push_missing_operand passed" << std::endl;
}

void test_add_insufficient_operands() {
    std::vector<int> program = {PUSH, 5, ADD, HALT};  // ADD with only 1 value on stack
    BytecodeInterpreter interp(program);
    int result = execute_with_stderr_capture(interp);
    assert(result == 0);
    std::cout << "✓ test_add_insufficient_operands passed" << std::endl;
}

void test_large_numbers() {
    std::vector<int> program = {PUSH, 1000000, PUSH, 2000000, ADD, HALT};
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 3000000);
    std::cout << "✓ test_large_numbers passed" << std::endl;
}

int main() {
    std::cout << "Running edge case tests..." << std::endl;
    
    test_empty_program();
    test_halt_only();
    test_push_without_halt();
    test_add_without_halt();
    test_invalid_opcode();
    test_push_missing_operand();
    test_add_insufficient_operands();
    test_large_numbers();
    
    std::cout << "\nAll edge case tests passed!" << std::endl;
    return 0;
}
