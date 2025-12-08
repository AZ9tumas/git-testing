#include "bytecode_interpreter.h"
#include <cassert>
#include <iostream>

void test_push_single_value() {
    std::vector<int> program = {PUSH, 42, HALT};
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 42);
    std::cout << "✓ test_push_single_value passed" << std::endl;
}

void test_add_two_values() {
    std::vector<int> program = {PUSH, 5, PUSH, 3, ADD, HALT};
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 8);
    std::cout << "✓ test_add_two_values passed" << std::endl;
}

void test_add_negative_values() {
    std::vector<int> program = {PUSH, -5, PUSH, -3, ADD, HALT};
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == -8);
    std::cout << "✓ test_add_negative_values passed" << std::endl;
}

void test_add_zero() {
    std::vector<int> program = {PUSH, 10, PUSH, 0, ADD, HALT};
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 10);
    std::cout << "✓ test_add_zero passed" << std::endl;
}

void test_multiple_push_operations() {
    std::vector<int> program = {PUSH, 1, PUSH, 2, PUSH, 3, HALT};
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 3);  // Top of stack should be 3
    std::cout << "✓ test_multiple_push_operations passed" << std::endl;
}

int main() {
    std::cout << "Running basic operations tests..." << std::endl;
    
    test_push_single_value();
    test_add_two_values();
    test_add_negative_values();
    test_add_zero();
    test_multiple_push_operations();
    
    std::cout << "\nAll basic operations tests passed!" << std::endl;
    return 0;
}
