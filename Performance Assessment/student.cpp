//
//  student.cpp
//  Performance Assessment
//
//  Created by Jasvaran Mann on 3/6/25.
//

#include "student.hpp"
#include <iostream>


Student::Student (std::string studentID, std::string firstName,
                  std::string lastName, std::string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (size_t i = 0; i < 3; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
    
    this->degreeProgram = degreeProgram;
    
}

// getters
std::string Student::GetStudentID() const {
    return this->studentID;
}
std::string Student::GetFirstName() const {
    return this->firstName;
}
std::string Student::GetLastName() const {
    return this->lastName;
}
std::string Student::GetEmailAddress() const {
    return this->emailAddress;
}

DegreeProgram Student::GetDegreeProgram() const {
    return this->degreeProgram;
}

int Student::GetAge() const {
    return this->age;
}

int* Student::GetDaysInCourse() {
    return this->daysInCourse;
}
