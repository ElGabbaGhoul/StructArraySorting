//
// Created by Scott Nideffer on 5/8/24.
//

#include "required.hpp"
#include "helper.hpp"
#include <iostream>
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
    // Display Unsorted
    // std::cout << "Unsorted Array: " << std::endl;
    // for (int i = 0; i < arrSize; i++) {
    //     std::cout << i + 1
    //     << ": " << "L00" << arr[i].lNum
    //     << " " << arr[i].nameF
    //     << " " << arr[i].nameL
    //     << " " << arr[i].GPA
    //     << std::endl;
    // }
    // // Display sorted by first
    // std::cout << "Sorted Array by First: " << std::endl;
    // std::sort(&arr[0], &arr[arrSize], sortByFirst);
    // for (int i = 0; i < arrSize; i++) {
    //     std::cout << i + 1
    //     << ": " << "L00" << arr[i].lNum
    //     << " " << arr[i].nameF
    //     << " " << arr[i].nameL
    //     << " " << arr[i].GPA
    //     << std::endl;
    // }
        // Display sorted by Lnum
        std::cout << "Sorted Array by LNumber: " << std::endl;
        std::sort(&arr[0], &arr[arrSize], sortByLNum);
    for (int i = 0; i < arrSize; i++) {
        std::cout << i + 1
        << ": " << "L00" << arr[i].lNum
        << " " << arr[i].nameF
        << " " << arr[i].nameL
        << " " << arr[i].GPA
        << std::endl;

        // Display Sorted by last
        std::cout << "Sorted Array by Last: " << std::endl;
        std::sort(&arr[0], &arr[arrSize], sortByLast);
        for (int i = 0; i < arrSize; i++) {
            std::cout << i + 1
            << ": " << "L00" << arr[i].lNum
            << " " << arr[i].nameF
            << " " << arr[i].nameL
            << " " << arr[i].GPA
            << std::endl;
        }
    }
}

bool binSearch(Student *arr, std::string q, int numStds) {
        int l = 0;
        int r = numStds - 1;
        int index;

        while (l <= r) {
            index = (l + r) / 2;
            // if lookat is name
            if (q < arr[index].nameL) {
                r = index - 1;
            } else if (q > arr[index].nameL) {
                l = index + 1;
            } else {
                std::string student = arr[index].nameL;
                std::cout << arr[index].nameF << " ";
                std::cout << arr[index].nameL << " ";
                std::cout << arr[index].GPA << "." << std::endl;
                l = r + 1;
                return true;
            }

            // if (arr[lookat].nameL == q) {
            //     std::cout << arr[lookat].nameF << " ";
            //     std::cout << arr[lookat].nameL << " ";
            //     std::cout << arr[lookat].GPA << "." << std::endl;
            // } else if ( q < arr[lookat].nameL) {
            //     min = lookat + 1;
            // } else {
            //     min = lookat + 1;
            // }
            return false;
        }
}



//     if (q < arr[lookat].nameL){
//         max = lookat - 1;
//     } else if (q > arr[lookat].nameL){
//         min = lookat + 1;
//     } else {
//         index = lookat;
//         min = max + 1;
//         return true;
//     }
// }
// return false;


// Tried implementing recursive binary search
// It wasn't working ToT

//    if (totalLines >= l) {
//        int mid = l + (totalLines - 1) / 2;
//        if(namesArray[mid] == query) {
//            return true;
//        }
//        if (namesArray[mid] > query) {
//            return binSearch(namesArray, l, mid - 1, query);
//        }
//
//        return binSearch(namesArray, mid + 1, totalLines, query);
//    }
//
//    return false;