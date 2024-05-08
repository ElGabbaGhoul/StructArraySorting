#include <iostream>
#include "required.hpp"


int main()
{
    int min = 1;
    int max = 20;


    int numStds = getInteger(1,20);
    createArray(numStds);
    std::cout << "Number of students: " << numStds << "." << std::endl;


    return 0;
}
