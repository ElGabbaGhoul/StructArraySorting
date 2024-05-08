#include <iostream>
#include "required.hpp"


int main()
{
    int min = 1;
    int max = 20;


    int numStds = getInteger(1,20);
    std::cout << "Number of students: " << numStds << "." << std::endl;


    return 0;
}
