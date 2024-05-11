//
// Created by Scott Nideffer on 5/8/24.
//
#include <iostream>
#include "helper.hpp"
#include "required.hpp"

//void insertArray() {
//    /*
//◦ pass in the array containing the new item in the last location
//◦ pass in the current count of items and the size of the array
//◦ insert the new item in the proper location in the array
//◦ update the array via reference
//◦ no return values
// **/
//}

std::string getFirstName() {
    std::string firstName;
    bool validFirst = false;

    while(!validFirst) {
        std::cout << "Student first name: " << std::endl;
        std::cin >> firstName;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(50000, '\n');
            std::cerr << "Invalid type of input." << std::endl;
            std::cerr << "Idk how you managed to screw this up?" << std::endl;
        } else {
            // every character tolower
            for (char &c : firstName) {
                c = std::tolower(c);
            }

            // first character toupper
            if (!firstName.empty()) {
                firstName[0] = std::toupper(firstName[0]);
            }

            // exit loop
            validFirst = true;
        }
    }
    return firstName;
}

std::string getLastName() {
    std::string lastName;
    bool validLast = false;

    while(!validLast) {
        std::cout << "Student last name: " << std::endl;
        std::cin >> lastName;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(50000, '\n');
            std::cerr << "Invalid type of input." << std::endl;
            std::cerr << "Idk how you managed to screw this up?" << std::endl;
        } else {
            // every character tolower
            for (char &c : lastName) {
                c = std::tolower(c);
            }

            // first character toupper
            if (!lastName.empty()) {
                lastName[0] = std::toupper(lastName[0]);
            }

            // exit loop
            validLast = true;
        }
    }
    return lastName;
}

std::string getSearchLast() {
    std::string lastName;
    bool validLast = false;

    while(!validLast) {
        std::cout << "Search for a student via last name: " << std::endl;
        std::cin >> lastName;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(50000, '\n');
            std::cerr << "Invalid type of input." << std::endl;
            std::cerr << "Idk how you managed to screw this up?" << std::endl;
        } else {
            // every character tolower
            for (char &c : lastName) {
                c = std::tolower(c);
            }

            // first character toupper
            if (!lastName.empty()) {
                lastName[0] = std::toupper(lastName[0]);
            }

            // exit loop
            validLast = true;
        }
    }
    return lastName;

}


bool sortByLast(Student &a, Student&b) {
    return a.nameL < b.nameL;
}

// never used, delete
bool sortByFirst(Student &a, Student&b) {
    return a.nameF < b.nameF;
}

bool sortByLNum(Student &a, Student &b) {
    return a.lNum < b.lNum;
}

bool isAllDigits(const std::string& str){
    for (char c : str){
        if (!isdigit(c)){
            return false;
        }
    }
    return true;
}