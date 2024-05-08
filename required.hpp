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
    //float GPA;
};

// Required Functions
int getInteger(int min, int max);
std::string getLnumber();
float getGPA();
//Function needs to return array...array is struct...
Student* createArray(int arrSize);
void displayArrays();
bool binSearch();

#endif //REQUIRED_HPP
