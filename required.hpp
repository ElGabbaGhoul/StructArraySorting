//
// Created by Scott Nideffer on 5/8/24.
//

#ifndef REQUIRED_HPP
#define REQUIRED_HPP

#include <iostream>

// Student Struct
struct Student {
    std::string lNum;
    std::string nameF;
    std::string nameL;
    float GPA;
};

// Required Functions

// gets integer for # of students
int getInteger(int min, int max);
// gets lnumber
std::string getLnumber();
// gets gpa
float getGPA();
// creates student struct arrays
Student* createArray(int arrSize);
// displays arrays sorted by last / lnum
void displayArrays(Student *arr, int arrSize);
// binary search for searching by lastname
bool binSearch(Student *arr, std::string q, int numStds);

#endif //REQUIRED_HPP
