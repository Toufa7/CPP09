#include "rpn.hpp"
#include <iomanip>

int main(int ac, char *av[])
{
    rpn obj;
    if (ac != 2)
    {
        std::cerr << "Error\n";
        exit(0);
    }
    else
    {
        try
        {
            obj.ReadInput(av[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what();
        }
        
    }
}

