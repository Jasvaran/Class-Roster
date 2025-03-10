//
//  student.cpp
//  Performance Assessment
//
//  Created by Jasvaran Mann on 3/6/25.
//

#include "student.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

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

DegreeProgram Student::GetDegreeProgram() const {

    return this->degreeProgram;
    
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
    
    std::stringstream ss;
    std::string firstName;
    DegreeProgram degreeProgram = this->GetDegreeProgram();
    ss << std::left << std::setw(5) << this->GetStudentID() << "\t"
                    << std::setw(12) << this->GetFirstName() << "\t"
                    << std::setw(12) << this->GetLastName() << "\t"
                    << std::setw(5) << this->GetAge() << "\t"
                    << "{" << this->GetDaysInCourse() << "}" <<std::setw(5) <<"\t";
    
    if (degreeProgram == DegreeProgram::SECURITY){
        ss << std::setw(10) << "Security" << std::endl;
    } else if (degreeProgram == DegreeProgram::NETWORK){
        ss << std::setw(10) << "Network" << std::endl;
    } else if (degreeProgram == DegreeProgram::SOFTWARE){
        ss << std::setw(10) << "Software" <<std::endl;
    };
                    
    std::cout << ss.str();
    
   
}

int* Student::GetDaysInCourseArr()  {
    return this->daysInCourse;
}
