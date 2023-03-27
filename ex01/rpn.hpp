#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <stack>

class rpn
{
    private:
        std::stack<int>     _numbers;
    public:
        rpn ();
        rpn (const rpn &a);
        ~rpn ();
        rpn & operator = (const rpn &a);

        void    ReadInput(std::string input);
        int     CalculationResult(int n1, int n2, char o);
};

#endif