#include "PmergeMe.hpp"

bool flag = false;
unsigned int tmp;

void    PrintContainer(const std::vector<unsigned int> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
}

void    SortPair(std::vector<std::pair<unsigned int,unsigned int> > &a)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i].first > a[i].second)
            std::swap(a[i].first, a[i].second);
    }
}

void    GetAndInsert(std::vector<unsigned int> &largest, std::vector<unsigned int> &smallest)
{
    for (size_t i = 0; i < largest.size(); i++)
        smallest.insert(std::lower_bound(smallest.begin(), smallest.end(), largest[i]), largest[i]);
    if (flag)
        smallest.insert(std::lower_bound(smallest.begin(), smallest.end(), tmp), tmp);
    PrintContainer(smallest);
}


void    ExtractingLargestNumbers(std::vector<std::pair<unsigned int, unsigned int> > &a)
{
    std::vector<unsigned int> largest, smallest;

    for (size_t i = 0; i < a.size(); i++)
        smallest.push_back(a[i].first);

    for (size_t i = 0; i < a.size(); i++)
        largest.push_back(a[i].second);

    std::sort(smallest.begin(), smallest.end());
    GetAndInsert(largest, smallest);
}



// void    PrintStat(char **av, int ac)
// {
//     std::cout << "Before : "; 
//     if (ac < 6)
//     {
//         for (size_t i = 1; i < 6; i++)
//             std::cout << av[i] << " ";
//     }
//     else
//     {
//         for (size_t i = 1; i < 6; i++)
//             std::cout << av[i] << " ";
//         std::cout << "[...]";
//     }
// }

int main(int ac, char *av[])
{   
    if ((ac - 1) % 2 != 0)
    {
        flag = true;
        tmp = std::atoi(av[ac - 1]);
        ac-=1;
    }
    
    std::vector<std::pair<unsigned int, unsigned int> > myvec;
    for (int i = 1; i < ac; i+=2)
    {
        if (isdigit(*av[i]))
            myvec.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
    }
    SortPair(myvec);
    ExtractingLargestNumbers(myvec);
}