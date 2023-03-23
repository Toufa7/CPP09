#ifndef RPN_H
#define RPN_H
#include <iostream>
#include <stack>


class rpn
{
    private:
        std::stack<int>     _numbers;
        std::stack<char>    _operators;
    public:
        rpn ();
        rpn (const rpn &a);
        ~rpn ();
        rpn & operator = (const rpn &a);

        void    ReadInput(std::string input);
        void    PrintStack(char c);
        void    CheckErrors();
        int     CalculationResult(int n1, int n2, char o);
        void    Calculation();
};

#endif