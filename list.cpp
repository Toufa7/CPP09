#include <iostream>
#include <list>
#include <algorithm>

void    PrintStats(std::list<std::pair<unsigned int, unsigned int> > &lst)
{
    std::list<std::pair<unsigned int, unsigned int> >::iterator ite = lst.begin();
    for (; ite != lst.end() ; ++ite)
    {
        std::cout << "{"<< ite->first << " , " << ite->second << "}" << "\n";

    }    
}

int main(int ac, char *av[])
{
    std::list<std::pair<unsigned int, unsigned int> > lst;
    for (int i = 1; i < ac ; i+=2)
    {
       if (isdigit(*av[i]))
            lst.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
    }

    PrintStats(lst);

    std::list<std::pair<unsigned int, unsigned int> >::iterator ite = lst.begin();
    std::cout << "\n******\n";
    for (; ite != lst.end() ; ++ite)
    {
        if (ite->first > ite->second)
            std::swap(ite->first, ite->second);
    }
    PrintStats(lst);


    std::list<unsigned int> lst_a;
    ite = lst.begin();
    for (; ite != lst.end() ; ++ite)
        lst_a.push_back(ite->first);


    std::list<unsigned int> lst_b;
    ite = lst.begin();
    for (; ite != lst.end() ; ++ite)
        lst_b.push_back(ite->second);

    lst_a.sort();

    std::list<unsigned int>::iterator itb = lst_b.begin();

    for (; ite != lst_b.end() ; ++ite)  
        lst_a.push_back(ite->first);

}



//                          LIST

    // std::list<std::pair<unsigned int, unsigned int> > lst;
    // for (int i = 1; i < ac; i+=2)
    // {
    //     if (isdigit(*av[i]))
    //         lst.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
    // }
    // std::list<unsigned int> lst_a, lst_b;
    // algo(ac, av, lst, lst_a, lst_b);