//
// Created by Scott Nideffer on 5/8/24.
//

#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include "required.hpp"

//void insertArray(); I never found a use for this
// checks to make sure everything is a digit
bool isAllDigits(const std::string& str);
// gets sanitized input for firstname
std::string getFirstName();
// gets sanitized input for lastname
std::string getLastName();
// compares 2 input structs to see which comes before
bool sortByLast(Student &a, Student&b);
bool sortByLNum(Student&a, Student&b);
// gets input string for searching by lastname
std::string getSearchLast();
#endif //HELPER_H
