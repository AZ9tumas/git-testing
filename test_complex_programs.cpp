#include "bytecode_interpreter.h"
#include <cassert>
#include <iostream>

void test_chain_additions() {
    // Test: 10 + 20 + 30
    std::vector<int> program = {
        PUSH, 10,
        PUSH, 20,
        ADD,
        PUSH, 30,
        ADD,
        HALT
    };
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 60);
    std::cout << "✓ test_chain_additions passed" << std::endl;
}

void test_long_chain_additions() {
    // Test: 1 + 2 + 3 + 4 + 5
    std::vector<int> program = {
        PUSH, 1,
        PUSH, 2,
        ADD,
        PUSH, 3,
        ADD,
        PUSH, 4,
        ADD,
        PUSH, 5,
        ADD,
        HALT
    };
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 15);
    std::cout << "✓ test_long_chain_additions passed" << std::endl;
}

void test_mixed_positive_negative() {
    // Test: 100 + (-50) + 25
    std::vector<int> program = {
        PUSH, 100,
        PUSH, -50,
        ADD,
        PUSH, 25,
        ADD,
        HALT
    };
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 75);
    std::cout << "✓ test_mixed_positive_negative passed" << std::endl;
}

void test_result_zero() {
    // Test: 50 + (-50)
    std::vector<int> program = {
        PUSH, 50,
        PUSH, -50,
        ADD,
        HALT
    };
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 0);
    std::cout << "✓ test_result_zero passed" << std::endl;
}

void test_complex_calculation() {
    // Test: ((100 + 200) + (300 + 400))
    // First: 100 + 200 = 300
    // Then: 300 + 400 = 700
    // Finally: 300 + 700 = 1000
    std::vector<int> program = {
        PUSH, 100,
        PUSH, 200,
        ADD,        // Stack: [300]
        PUSH, 300,
        PUSH, 400,
        ADD,        // Stack: [300, 700]
        ADD,        // Stack: [1000]
        HALT
    };
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 1000);
    std::cout << "✓ test_complex_calculation passed" << std::endl;
}

void test_many_operations() {
    // Test multiple consecutive operations
    // 5 + 10 + 15 + 20 + 25 + 30 + 35 + 40 + 45 + 50
    std::vector<int> program = {
        PUSH, 5,
        PUSH, 10,
        ADD,
        PUSH, 15,
        ADD,
        PUSH, 20,
        ADD,
        PUSH, 25,
        ADD,
        PUSH, 30,
        ADD,
        PUSH, 35,
        ADD,
        PUSH, 40,
        ADD,
        PUSH, 45,
        ADD,
        PUSH, 50,
        ADD,
        HALT
    };
    BytecodeInterpreter interp(program);
    int result = interp.execute();
    assert(result == 275);
    std::cout << "✓ test_many_operations passed" << std::endl;
}

int main() {
    std::cout << "Running complex program tests..." << std::endl;
    
    test_chain_additions();
    test_long_chain_additions();
    test_mixed_positive_negative();
    test_result_zero();
    test_complex_calculation();
    test_many_operations();
    
    std::cout << "\nAll complex program tests passed!" << std::endl;
    return 0;
}
