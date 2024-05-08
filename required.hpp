//
// Created by Scott Nideffer on 5/8/24.
//

#ifndef REQUIRED_HPP
#define REQUIRED_HPP

#include <iostream>

// Required Functions
int getInteger(int min, int max);
std::string getLnumber();
float getGPA();
//Function needs to return array...array is struct...
std::string createArray();
void displayArrays();
bool binSearch();

// Student Struct
struct Student {
    std::string lNum;
    std::string nameF;
    std::string nameL;
    float GPA;
};

#endif //REQUIRED_HPP
