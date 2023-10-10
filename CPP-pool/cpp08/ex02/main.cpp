#include "MutantStack.hpp"

int main()
{

    MutantStack<int> mstack;

    std::cout << "----------" << std::endl;

    std::cout << "we push 5 and 17 in the MutantStack" << std::endl;

    mstack.push(5);
    mstack.push(17);

    std::cout << "----------" << std::endl;

    std::cout << "top of stack: " << mstack.top() << std::endl;
    std::cout << "size: "<< mstack.size() << std::endl;

    std::cout << "----------" << std::endl;

    std::cout << "we pop the top number of the MutantStack so now we have" << std::endl;
    mstack.pop();

    std::cout << "----------" << std::endl;

    std::cout << "top of stack: " << mstack.top() << std::endl;
    std::cout << "size: "<< mstack.size() << std::endl;

    std::cout << "----------" << std::endl;

    std::cout << "we push 3, 5, 737 and 0 in the MutantStack so now we have" << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "----------" << std::endl;

    std::cout << "top of stack: " << mstack.top() << std::endl;
    std::cout << "size: "<< mstack.size() << std::endl;
    
    std::cout << "----------" << std::endl;

    MutantStack<int>::iterateur start = mstack.begin(); 
    MutantStack<int>::iterateur end = mstack.end();

    std::cout << "start iterator: " << *start << std::endl;
	std::cout << "end iterator: " << *end << std::endl;
    
    start++;

    std::cout << "start iterator: " << *start << std::endl;
	std::cout << "end iterator: " << *end << std::endl;

    start--;

    std::cout << "start iterator: " << *start << std::endl;
	std::cout << "end iterator: " << *end << std::endl;
    
    std::cout << "----------" << std::endl;

    std::cout << "we iterate through the MutantStack with the iterators" << std::endl;

    std::cout << "----------" << std::endl;

    while (start != end)
    {
        std::cout << *start << std::endl;
        start++; 
    }

    std::cout << "----------" << std::endl;

    std::cout << "we can check if the MutanStack is empty or not with .empty()" << std::endl;

    std::cout << "----------" << std::endl;

    MutantStack<int> empty;

    std::cout << "empty: " << mstack.empty() << std::endl;
    std::cout << "empty: " << empty.empty() << std::endl;

    std::cout << "----------" << std::endl;

    return 0;
}
