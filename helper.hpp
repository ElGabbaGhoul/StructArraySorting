//
// Created by Scott Nideffer on 5/8/24.
//

#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include "required.hpp"

void insertArray();
std::string getFirstName();
std::string getLastName();
bool sortByLast(Student &a, Student&b);
bool sortByFirst(Student &a, Student&b);
bool sortByLNum(Student&a, Student&b);
std::string getSearchLast();
#endif //HELPER_H
