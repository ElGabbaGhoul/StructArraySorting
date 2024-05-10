#include <iostream>

#include "helper.hpp"
#include "required.hpp"

// It will then use std::sort to sort the array by lastName and call displayArray
// again to show the new sorting.


// Finally it will loop five times getting a lastName,
// searching the array for that name, and, if the name is present, displaying the firstName,
// lastName and GPA.

int main(){
    int searches = 0;
    int numStds = getInteger(1,20);
    Student *students = createArray(numStds);
    std::cout << "Number of students: " << numStds << "." << std::endl;
    // DisplayArrays sorted by LNum, then displays sorted by last
    displayArrays(students, numStds);
    // Search for 5 students by Last name
    // display first, last, GPA
    do {
        std::string query = getSearchLast();
        binSearch(students, query, numStds);
        if (binSearch(students, query, numStds)) {
            // print first, last, gpa
            std::cout << students->nameF << " " << students->nameL << ", " << students->GPA << "." << std::endl;
        }
        searches++;
        std::cout << searches << " searches of 5 used." << std::endl;
    } while (searches <= 5);




    return 0;
}
