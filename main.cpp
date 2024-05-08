#include <iostream>
#include "required.hpp"


int main(){
    int numStds = getInteger(1,20);
    Student *students = createArray(numStds);
    std::cout << "Number of students: " << numStds << "." << std::endl;
    displayArrays(students, numStds);


    return 0;
}
