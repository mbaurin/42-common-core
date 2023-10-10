#include "easyfind.hpp"

int main()
{
    std::array<int, 5> a = {12, 24, 8, 0, 112};

    try
    {
        std::cout << "The function research 0: " << easyfind(a, 0) << std::endl;
        std::cout << "The function research 112: " << easyfind(a, 112) << std::endl;
        std::cout << "The function research 34: " << easyfind(a, 34) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
