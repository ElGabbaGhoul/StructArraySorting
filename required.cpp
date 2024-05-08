//
// Created by Scott Nideffer on 5/8/24.
//

#include "required.hpp"
#include "helper.hpp"
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
    std::string lNumIn;
    bool validLNum;

    while (!validLNum) {
        std::cout << "What is this student's L-Number?" << std::endl;
        std::cout << "L00XXXXXX: " << std::endl;
        std::cin >> lNumIn;
        if (std::cin.fail()) {
            // type check
            std::cin.clear();
            std::cin.ignore(50000, '\n');
            std::cerr << "Invalid type of input." << std::endl;
            std::cerr << "Please enter the right thing dingus" << std::endl;
        } else if (lNumIn < "111111" || lNumIn > "999999") {
            // range check
            std::cin.clear();
            std::cin.ignore(50000, '\n');
            std::cerr << "Invalid type of input." << std::endl;
            std::cerr << "Please enter a string of 6 digits between 111111 and 999999" << std::endl;
        } else {
            validLNum = true;
        }
    }
    return lNumIn;
}

float getGPA() {
    // ◦ gets and validates a GPA
    float GPAIn;
    bool validGPA = false;

    while (!validGPA) {
        std::cout << "What is this student's GPA: " << std::endl;
        std::cin >> GPAIn;

        // type check
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(50000, '\n');
            std::cerr << "Invalid type of input." << std::endl;
            std::cerr << "Please enter in the form of X.XX for GPA." << std::endl;
        } else if (GPAIn < 2.00 || GPAIn > 4.20) {
            // range check
            std::cin.clear();
            std::cin.ignore(50000, '\n');
            std::cerr << "Input out of range." << std::endl;
            std::cerr << "Input should be between 2.00 and 4.20" << std::endl;
        } else {
            // valid input
            validGPA = true;
        }
    }
    return GPAIn;
    // ◦ returns it as a float
}

Student* createArray(int arrSize) {
    Student* students = new Student[arrSize];

    for (int i = 0; i < arrSize; i++) {
        std::string lNumIn = getLnumber();
        std::string firstIn = getFirstName();
        std::string lastIn = getLastName();
        float GPA = getGPA();

        students[i].lNum = lNumIn;
        students[i].nameF = firstIn;
        students[i].nameL = lastIn;
        students[i].GPA = GPA;
    }

    return students;
}

void displayArrays(Student *arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        std::cout << i + 1
        << ": " << "L00" << arr[i].lNum
        << " " << arr[i].nameF
        << " " << arr[i].nameL
        << " " << arr[i].GPA
        << std::endl;
    }
    // ◦ display the arrays in columns firstName, lastName, Lnumber, and GPA
    // ◦ no return values
}

bool binSearch() {

}
