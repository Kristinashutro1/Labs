#include "calculator.h"
#include <stdexcept>
#include <cctype>

int Calculator::getPriority(char op) const {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int Calculator::performOperation(int a, int b, char op) const {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Division by zero");
            }
            return a / b;
        default:
            throw std::runtime_error("Unknown operator");
    }
}

bool Calculator::isOperator(char c) const {
    return c == '+' || c == '*' || c == '-' || c == '/';
}

bool Calculator::isDigit(char c) const {
    return std::isdigit(c);
}

bool Calculator::validateExpression(const std::string& expression) const {
     Stack parentheses;
    bool lastWasOperator = true;
    bool lastWasDigit = false;
    bool expectDigit = true;
    
    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];
        
        if (c == ' ') {
            continue;
        }
        
        if (c == '(') {
            parentheses << c;
            expectDigit = true;
            lastWasOperator = true;
            lastWasDigit = false;
        } 
        else if (c == ')') {
            if (parentheses.isEmpty() || lastWasOperator) {
                return false;
            }
            parentheses.pop();
            lastWasDigit = true;
            lastWasOperator = false;
            expectDigit = false;
        }
        else if (isDigit(c)) {
            if (!expectDigit) {
                return false;
            }
            
            
        else if (isOperator(c)) {
            if (lastWasOperator && c != '-') {
                return false;
            }
            lastWasOperator = true;
            lastWasDigit = false;
            expectDigit = true;
        }
        else {
            return false; 
        }
    }
    
    return parentheses.isEmpty() && !lastWasOperator;
}

int Calculator::evaluateExpression(const std::string& expression) {
    Stack values;
    Stack operators;
    if (!validateExpression(expression)) {
        throw std::invalid_argument("Invalid expression");
    }
    
    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];
        
        if (c == ' ') {
            continue;
        }
        
        else if (c == '(') {
            operators.push('(');
        } else if (isDigit(c)) {
            int num = 0;
            while (i < expression.length() && isDigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            values.push(num);
        } else if (c == ')') {
            while (!operators.isEmpty() && operators[operators.size()-1] != '(') {
                char op = operators.pop();
                int b = values.pop();
                int a = values.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.pop();
        } else if (isOperator(c)) {
            while (!operators.isEmpty() && getPriority(operators[operators.size()-1]) >= getPriority(c)) {
                char op = operators.pop();
                int b = values.pop();
                int a = values.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(c);
        }
    }
    
    while (!operators.isEmpty()) {
        char op = operators.pop();
        int b = values.pop();
        int a = values.pop();
        values.push(applyOperation(a, b, op));
    }
    
    return values.pop();
}

    void Calculator::setExpression(const std::string& expr) {
        expression = expr;
    }