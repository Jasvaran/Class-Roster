//
//  student.cpp
//  Performance Assessment
//
//  Created by Jasvaran Mann on 3/6/25.
//

#include "student.hpp"
#include <iostream>
#include <iomanip>

Student::Student() {};
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

std::string Student::GetDegreeProgram() const {
    switch (this->degreeProgram) {
        case DegreeProgram::SECURITY:
            return "SECURITY";
            break;
        case DegreeProgram::NETWORK:
            return "NETWORK";
        case DegreeProgram::SOFTWARE:
            return "SOFTWARE";
        default:
            break;
    }
}

int Student::GetAge() const {
    return this->age;
}

std::string Student::GetDaysInCourse() const {
    std::string str;
    for (size_t i = 0; i < 3; ++i) {
        if (i <= 1) {
            str += std::to_string(this->daysInCourse[i]) + ",";
        } else {
            str += std::to_string(this->daysInCourse[i]);
        }
    }
    return str;
}



// Setters

void Student::SetStudentID(std::string studentID){
    this->studentID = studentID;
}

void Student::SetFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Student::SetLastName(std::string lastName){
    this->lastName = lastName;
}

void Student::SetEmailAddress(std::string emailAddress){
    this->emailAddress = emailAddress;
}

void Student::SetAge(int age){
    this->age = age;
}

void Student::SetDaysInCourse(int* daysInCourse){
    for (size_t i = 0; i < 3; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram){
    this->degreeProgram = degreeProgram;
}

void Student::Print() const {
    std::cout << this->GetStudentID() << "\t" << this->GetFirstName() << "\t" << this->GetLastName() << "\t" <<
    this->GetEmailAddress() << "\t" << this->GetAge() << "\t" << "{" << this->GetDaysInCourse() << "}" <<
    "\t" << this->GetDegreeProgram() << std::endl;
}

int* Student::GetDaysInCourseArr()  {
    return this->daysInCourse;
}
