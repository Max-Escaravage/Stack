#include "myStack.h"

int evaluatePostfix(std::string exp);

int main()
{
    std::cout << evaluatePostfix("234*+") << std::endl;

    system("PAUSE");
    return 0;
}

int evaluatePostfix(std::string exp)
{
    myStack<int> s(100);

    for (int i = 0; i < exp.length(); i++)
    {
        // Operand
        if (isdigit(exp[i]))
        {
            int num = exp[i] - '0';
            s.push(num);
        }
        // Operator
        else
        {
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();

            switch (exp[i])
            {
                case '+':
                    s.push(num2 + num1);
                    break;
                case '-':
                    s.push(num2 - num1);
                    break;
                case '*':
                    s.push(num2 * num1);
                    break;
                case '/':
                    s.push(num2 / num1);
                    break;
            }
        }
    }

    int result = s.top();
    s.pop();
    return result;
}