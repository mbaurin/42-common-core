#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>

void    searchAndReplace(char **argv)
{
    std::string	    result;
    std::ifstream	inputFileStream;
    std::string     replacement = argv[3];
    std::string     stringToReplace = argv[2];
    size_t		    toReplaceLen = stringToReplace.length();

    inputFileStream.open(argv[1], std::ifstream::in);   
    if (inputFileStream.is_open())
    {
        result.assign(std::istreambuf_iterator<char>(inputFileStream), std::istreambuf_iterator<char>());
        for (size_t pos = 0; pos < result.length(); pos++)
        {
            if (result.compare(pos, toReplaceLen, stringToReplace) == 0)
            {
                result.erase(pos, toReplaceLen);
                result.insert(pos, replacement);
                pos += toReplaceLen;
            }
        }
        
        std::string     output_name(argv[1]);
        std::ofstream outputFileStream(output_name.append(".replace"));
        outputFileStream << result;

        inputFileStream.close();
        outputFileStream.close();
    }
    else
    {
        std::cout << "Issue with the file you pass" << std::endl;
    }
}

int main (int argc , char **argv)
{
    if (argc != 4)
    {
        std::cout << "You must put 3 parameters to use sed" << std::endl;
        return 0;
    }
    else
    {
        searchAndReplace(argv);
    }
}
