#include "PmergeMe.hpp"

PmergeMe::PmergeMe ()
{
}

/*--------------------------------------------------------*/
PmergeMe::PmergeMe (const PmergeMe &a)
{
        this->operator=(a);
}

/*--------------------------------------------------------*/
PmergeMe::~PmergeMe ()
{
}

/*--------------------------------------------------------*/
PmergeMe & PmergeMe::operator = (const PmergeMe &a)
{
        (void)a;
        return(*this);
}

