#include "iter.hpp"

int main()
{
    std::string tab[4] = {
        "My",
        "name", 
        "is",
        "mbaurin",
        };

    iter(tab, 4, &print);

    std::cout << std::endl;

    int otherTab[5] = {
        1,
        2,
        3,
        4,
        5
    };

    iter(otherTab, 5, &print);

    return 0;
}
