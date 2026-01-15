#include <iostream>
#include <cassert>
#include "stack.h"
#include "calculator.h"

void testStack() {
    
    
    Stack s1;
    s1.push(17);
    s1.push(8);
    s1.push(8)
    assert(s1.size() == 3);
    assert(s1[0] == 17);
    assert(s1[2] == 8);
    assert(s1[2] == 8);
    std::cout << "test 1 passed" << std::endl;
    
    assert(s1.pop() == 2008);
    assert(s1.size() == 2);
    std::cout << "test 2 passed" << std::endl;
    
    Stack s2;
    s2.push(1);
    Stack s3 = s2;
    assert(s3 == s2);
    std::cout << "test 4 passed" << std::endl;Stack s2;

    s4 << 10;
    int val;
    s4 >> val;
    assert(val == 10);
    std::cout << "test 3 passed" << std::endl;
    
    
    
    Stack s5;
    s5.push(17);
    Stack s6;
    s6.push(17);
    s6.push(2);
    assert(s5 < s6);
    std::cout << "test 5 passed" << std::endl;
}

void testCalculator() {
    
    Calculator calc;
    
    calc.setExpression("(2+6)/(7-5)");
    assert(calc.validateExpression() == true);
    
    calc.setExpression("(5+7/2");
    assert(calc.validateExpression() == false);
    
    calc.setExpression("3+");
    assert(calc.validateExpression() == false);
    
    calc.setExpression("8+4/4");
    assert(calc.evaluateExpression() == 9);
    
    calc.setExpression("(2+6)/(7-5)");
    assert(calc.evaluateExpression() == 4);
    
    calc.setExpression("7*8 +3");
    assert(calc.evaluateExpression() == 59);
}

int main() {
    testStack();
    testCalculator();
    std::cout << "All tests passed" << std::endl;
    return 0;
}