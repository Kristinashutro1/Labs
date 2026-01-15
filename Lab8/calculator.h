#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <cmath>
#include "stack.h"

class Calculator {
private:
    //приоритет +
    int getPriority(char op) const;
    
    //выполнение операции +
    int performOperation(int a, int b, char op) const;
    
    //проверка символов +
    bool isOperator(char c) const;
    bool isDigit(char c) const;
    
    
public:
    Calculator() = default;
    

    bool validateExpression(const std::string& expression) const;    //+
    int evaluateExpression(const std::string& expression);          //
    void setExpression(const std::string&expr);                     //+
    
};

#endif // CALCULATOR_H