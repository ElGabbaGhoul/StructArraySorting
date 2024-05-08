//
// Created by Scott Nideffer on 5/8/24.
//

#include "required.hpp"
#include <iostream>

// Required Functions
int getInteger(int min, int max) {
    /*◦ pass in min and max value
    ◦ gets and validates an integer between min and max
    ◦ returns the value*/
    int numStudents;
    bool validNum = false;

    while(!validNum) {
        std::cout << "Give me a number between " << min <<" and " << max << "." << std::endl;
        std::cin >> numStudents;
        // type failure
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(50000, '\n');
            std::cerr << "Invalid type of input." << std::endl;
            std::cerr << "Please enter a whole number between " << min <<" and " << max << "." <<  std::endl;
        // range failure
        } else if (numStudents < min || numStudents > max) {
            std::cin.clear();
            std::cin.ignore(50000, '\n');
            std::cerr << "Input outside of range." << std::endl;
            std::cerr << "Value should be between " << min <<" and " << max << "." <<  std::endl;
        } else {
            validNum = true;
        }
    }
    return numStudents;
}
std::string getLnumber() {

}
float getGPA() {

}


Student* createArray(int arrSize) {
    Student* students = new Student[arrSize];

    for (int i = 0; i < arrSize; i++) {
        std::string lNumIn, firstIn, lastIn;
        std::cout << "Give me the next student: Lnumber, first name, then last name." << std::endl;
        std::cin >> lNumIn >> firstIn >> lastIn;
        students[i].lNum = lNumIn;
        students[i].nameF = firstIn;
        students[i].nameL = lastIn;
    }

    for (int i = 0; i < arrSize; i++) {
        std::cout << i + 1 << ": " << students[i].lNum
        << " " << students[i].nameF
        << " " << students[i].nameL
        << std::endl;
    }
    return students;
}
void displayArrays() {

}
bool binSearch() {

}
