//
// Created by Scott Nideffer on 5/8/24.
//

#include "required.hpp"
#include "helper.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

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
    bool validLNum = false;

    do {
        std::cout << "What is this student's L-Number?" << std::endl;
        std::cout << "L00XXXXXX: " << std::endl;
        std::cin >> lNumIn;
        if (lNumIn.length() !=6 || !isAllDigits(lNumIn)) {
            // type check
            std::cin.clear();
            std::cin.ignore(50000, '\n');
            std::cerr << "Invalid type of input." << std::endl;
            std::cerr << "Please enter exactly 6 digits between 111111 and 999999." << std::endl;
        } else if (lNumIn < "111111" || lNumIn > "999999") {
            // range check
            std::cin.clear();
            std::cin.ignore(50000, '\n');
            std::cerr << "Input out of range." << std::endl;
            std::cerr << "Please enter exactly 6 digits between 111111 and 999999." << std::endl;
        } else {
            validLNum = true;
        }
    } while (!validLNum);
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
    return validGPA;
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
        // Display sorted by Lnum
        std::cout << "Sorted Array by LNumber: " << std::endl;
        std::sort(&arr[0], &arr[arrSize], sortByLNum);
    for (int i = 0; i < arrSize; i++) {
        std::cout << i + 1
                  << ": " << "L00" << arr[i].lNum
                  << " " << arr[i].nameF
                  << " " << arr[i].nameL
                  << " " << std::fixed << std::setprecision(2) << std::setw(4) << std::setfill('0') << arr[i].GPA + 1 << std::endl;
    }
        // Display Sorted by last
        std::cout << "Sorted Array by Last: " << std::endl;
        std::sort(&arr[0], &arr[arrSize], sortByLast);
        for (int i = 0; i < arrSize; i++) {
            std::cout << i + 1
            << ": " << "L00" << arr[i].lNum
            << " " << arr[i].nameF
            << " " << arr[i].nameL
            // format to always show 2 decimal precision
            << " " << std::fixed << std::setprecision(2) << std::setw(4) << std::setfill('0') << arr[i].GPA + 1 << std::endl;
        }
}

bool binSearch(Student *arr, std::string q, int numStds) {
        int l = 0;
        int r = numStds - 1;
        bool found = false;

        while (l <= r) {
            int index = (l + r) / 2;
            if (q < arr[index].nameL) {
                r = index - 1;
            } else if (q > arr[index].nameL) {
                l = index + 1;
            } else {
                found = true;
                std::cout << "Student(s) found with last name '" << q <<  "' found." << std::endl;

                // Print all students with same last name
                int i = index;
                while ( i >= l && arr[i].nameL == q){
                    std::cout << arr[i].nameL << ", ";
                    std::cout << arr[i].nameF << ".";
                    std::cout << " " << std::fixed << std::setprecision(2) << std::setw(4) << std::setfill('0') << arr[i].GPA + 1 << std::endl;
                    i--;
                }
                i = index + 1;
                while (i <= r && arr[i].nameL == q){
                    std::cout << arr[i].nameL << ", ";
                    std::cout << arr[i].nameF << ".";
                    std::cout << " " << std::fixed << std::setprecision(2) << std::setw(4) << std::setfill('0') << arr[i].GPA + 1 << std::endl;
                    i++;
                }
                // Exit loop
                l = r + 1;
            }
        }
    // None found
    if (!found){
        std::cerr << "No student with last name '" << q <<  "' found." << std::endl;
    }
    return found;
}