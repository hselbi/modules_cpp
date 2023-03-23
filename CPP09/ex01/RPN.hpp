#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>

class RPN
{
private:
    std::stack<float> stk;
public:
    RPN(void);
    RPN(const RPN &target);
    RPN operator=(const RPN &target);
    ~RPN();
    void polishCalculator(char *line);
};

#endif