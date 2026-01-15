#include <iostream>
#include "calculator.h"

void runCalculator() {
    Calculator calc;
    std::string expression;
    
    std::cout << "My calculator" << std::endl;
    std::cout << "operations +, -, *, /" << std::endl;
    
    
    std::string expression[] = {
        "(2+6)/(7-5)"
        "(5+7/2"
        "3+"
    };
    for (const auto& expr : expression) {
    calc.setExpression(expr); 
    
    std::cout << "expression: " << expr << std::endl;
    std::cout << "validity: " << (calc.validateExpression() ? "yes" : "no") << std::endl;
    
    if (calc.validateExpression()) {
        try {
            int result = calc.evaluateExpression();
            std::cout << "result: " << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << "bug: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
}
    std::cout << "demonstration of stack work" << std::endl;
    Stack s;
    s<< 7 << 17;
    for (int i = 0, i < s.size(); i ++) {
    std :: cout << s[i] << " "; }
    std :: cout << std :: endl;
}

int main() {
    runCalculator();
    return 0;
}