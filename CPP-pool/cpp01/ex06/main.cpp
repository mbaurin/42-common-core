#include "Karen.hpp"

int main(int argc, char **argv)
{
    Karen karen;
    
    if (argc != 2)
    {
        std::cout << "Arguments Error" << std::endl;
        return 0;
    }
    else
    {
        std::map<std::string, int> _filter;
        _filter["DEBUG"] = 1;
        _filter["INFO"] = 2;
        _filter["WARNING"] = 3;
        _filter["ERROR"] = 4;

        switch (_filter[argv[1]])
        {
            case 1:
            {
                std::cout << "[ DEBUG ]" << std::endl;
                karen.complain("debug");
                std::cout << "[ INFO ]" << std::endl;
                karen.complain("info");
                std::cout << "[ WARNING ]" << std::endl;
                karen.complain("warning");
                std::cout << "[ ERROR ]" << std::endl;
                karen.complain("error");
                break ;
            }
            case 2:
            {
                std::cout << "[ INFO ]" << std::endl;
                karen.complain("info");
                std::cout << "[ WARNING ]" << std::endl;
                karen.complain("warning");
                std::cout << "[ ERROR ]" << std::endl;
                karen.complain("error");
                break ;
            }
            case 3:
            {
                std::cout << "[ WARNING ]" << std::endl;
                karen.complain("warning");
                std::cout << "[ ERROR ]" << std::endl;
                karen.complain("error");
                break ;
            }
            case 4:
            {
                std::cout << "[ ERROR ]" << std::endl;
                karen.complain("error");
                break ;
            }
        }
    }
    return 0;
}