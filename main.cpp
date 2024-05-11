/*
Lab 5
Name: Scott "Marble" Nideffer
Date: 05/10/2024
IDE: Clion
Version: 1.0
Description: A program that creates student struct arrays with Firstname Lastname Lnumber and GPA, sorts them, and allows for
 a search of 5 students.
*/
#include <iostream>
#include "helper.hpp"
#include "required.hpp"

int main(){
    int searches = 0;
    // gets number of students
    int numStds = getInteger(1,20);
    // creates student struct array
    Student *students = createArray(numStds);
    std::cout << "Number of students: " << numStds << "." << std::endl;
    // displays arrays sorted by Lnumber then by lastname
    displayArrays(students, numStds);
    do {
        // allows for 5 lastname searches
        std::string query = getSearchLast();
        binSearch(students, query, numStds);
        searches++;
        std::cout << searches << " searches of 5 used." << std::endl;
    } while (searches < 5);

    std::cout << "Thank you for using Nideffer Industries' Student Lookup Program." << std::endl;

    return 0;
}
