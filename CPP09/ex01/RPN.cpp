#include "RPN.hpp"

RPN::RPN(void)
{}

RPN::RPN(const RPN &target)
{
    stk = target.stk;
}

RPN RPN::operator=(const RPN &target)
{
    if (&target != this)
        stk = target.stk;
    return (*this);
}

int wrongInput(char c)
{
    if (c == '*' || c == '+' || c == '-' || c == '/' || (c >= 48 && c <= 57))
        return 0;
    return 1;
}

void RPN::polishCalculator(char *line)
{
    int i = 0;
    while (line[i])
    {
        if (line[i] == ' ' || line[i] == '\t')
        {
            i++;
            continue;
        }
        if (wrongInput(line[i]))
        {
            std::cout << "Invalid input, please try again!" << std::endl;
            return ;
        }
        if (line[i] >= 48 && line[i] <= 57)
        {
            stk.push((line[i] - 48));
            i++;
        }
        else
        {
            if (stk.empty())
            {
                std::cout << "Error!" << std::endl;
                std::exit(1);
            }
            float tmp = stk.top();
            float res;
            switch (line[i])
            {
                case '*':
                    stk.pop();
                    if (stk.empty())
                    {
                        std::cout << "Error!" << std::endl;
                        std::exit(1);
                    }
                    res = stk.top() * tmp;
                    stk.pop();
                    stk.push(res);
                    i++;
                    continue;

                case '+':
                    stk.pop();
                    if (stk.empty())
                    {
                        std::cout << "Error!" << std::endl;
                        std::exit(1);
                    }
                    res = stk.top() + tmp;
                    stk.pop();
                    stk.push(res);
                    i++;
                    continue;

                case '-':
                    stk.pop();
                    if (stk.empty())
                    {
                        std::cout << "Error!" << std::endl;
                        std::exit(1);
                    }
                    res = stk.top() - tmp;
                    stk.pop();

                    stk.push(res);
                    i++;
                    continue;

                case '/':
                    stk.pop();
                    if (stk.empty())
                    {
                        std::cout << "Error!" << std::endl;
                        std::exit(1);
                    }
                    if (tmp == 0)
                    {
                        std::cout << "Error: Can't Devide by 0!" << std::endl;
                        std::exit(1);
                    }
                    res = stk.top() / tmp;
                    stk.pop();
                    stk.push(res);
                    i++;
                    continue;
                default:
                    break;
            }
        }
    }
    std::cout << stk.top() << std::endl;
    stk.pop();
    if (!stk.empty())
        std::cout << "unfortuanally we can't use this last one!" << std::endl;
}


RPN::~RPN()
{}