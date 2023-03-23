#ifndef __PMERGEME_H__
#define __PMERGEME_H__
#include <iostream>

class PmergeMe
{
    private:
        // your private members here
    public:
        PmergeMe ();
        PmergeMe (const PmergeMe &a);
        ~PmergeMe ();
        PmergeMe & operator = (const PmergeMe &a);
};

#endif

