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
//Function needs to return array...array is struct...
std::string createArray(int arrSize) {
    std::string **students;
//     ◦ pass in the desired size
// ◦ create an array of Student structs

    // I have no idea what to do here lmao
    students = new *struct Student[arrSize];
// ◦ then loop the proper number of times
//     ▪ get an Lnumber, firstName, lastName, GPA
// ◦ Return the array when done
}
void displayArrays() {

}
bool binSearch() {

}
