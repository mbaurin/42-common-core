#include <iostream>
#include <string>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "affichage grâce au pointeur " << stringPTR << std::endl;
    std::cout << "affichage grâce à la reference " << stringREF << std::endl;
}
