#include <iostream>
#include <cmath>
#include <string>

void displayChar(std::string str)
{
    int result;

    if (str.size() == 1 && isdigit(str[0]) == false)
        std::cout << static_cast<char>(str[0]) << std::endl;
    else
    {
        std::size_t lastChar;
        result = std::stoi(str, &lastChar, 10);
        if (isprint(result))
            std::cout << static_cast<char>(result) << std::endl;
        if (result <= 32 || result >= 127)
            std::cout << "Non displayable" << std::endl;
    }
}

void displayInt(std::string str)
{
    std::size_t lastChar;
    int result;

    result = std::stoi(str, &lastChar, 10);
    std::cout << static_cast<int>(result) << std::endl;
}

void displayFloat(std::string str)
{
    std::size_t lastChar;
    float result;

    result = std::stof(str, &lastChar);
    std::cout << static_cast<float>(result);
    if (roundf(result) == result)
        std::cout << ".0f";
    std::cout << std::endl;
}

void displayDouble(std::string str)
{
    std::size_t lastChar;
    double result;

    result = std::stod(str, &lastChar);
    std::cout << static_cast<double>(result);
    if (roundf(result) == result)
        std::cout << ".0";
    std::cout << std::endl;
}

//////////

void handleChar(std::string str)
{
    std::cout << "char: ";
    try
    {
        displayChar(str);
    }
    catch(std::invalid_argument)
    {
        std::cout << "Impossible" << std::endl;
    }
    catch(std::out_of_range&)
    {
        std::cout << "Non displayable" << std::endl;
    }
}

void handleInt(std::string str)
{
    std::cout << "int: ";
    try
    {
        displayInt(str);
    }
    catch(std::invalid_argument)
    {
        std::cout << "Impossible" << std::endl;
    }
    catch(std::out_of_range&)
    {
        std::cout << "Non displayable" << std::endl;
    }
}

void handleFloat(std::string str)
{
    std::cout << "float: ";
    try
    {
        displayFloat(str);
    }
    catch(std::invalid_argument)
    {
        std::cout << "Impossible" << std::endl;
    }
    catch(std::out_of_range&)
    {
        std::cout << "Non displayable" << std::endl;
    }
}

void handleDouble(std::string str)
{
    std::cout << "double: ";
    try
    {
        displayDouble(str);
    }
    catch(std::invalid_argument)
    {
        std::cout << "Impossible" << std::endl;
    }
    catch(std::out_of_range&)
    {
        std::cout << "Non displayable" << std::endl;
    }
}

void display(std::string str)
{
    handleChar(str);
    handleInt(str);
    handleFloat(str);
    handleDouble(str);
}

//////////

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Arguments Error" << std::endl;
        return 0;
    }
    else
    {
        std::string str;
        str = static_cast<std::string>(argv[1]);
        display(str);
    }
    return 0;

}
