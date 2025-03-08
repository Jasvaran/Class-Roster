//
//  roster.cpp
//  Performance Assessment
//
//  Created by Jasvaran Mann on 3/6/25.
//

#include "roster.hpp"
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

Roster::Roster(){};

DegreeProgram Roster::strToEnum(std::string& str){
    std::map<std::string, DegreeProgram> degreeProgramMap = {
        {"SECURITY", DegreeProgram::SECURITY},
        {"NETWORK" , DegreeProgram::NETWORK},
        {"SOFTWARE", DegreeProgram::SOFTWARE}
    };
    
    auto it = degreeProgramMap.find(str);
    if (it != degreeProgramMap.end()){
        return it->second;
    } else {
        throw std::invalid_argument(str);
    }
    
}

void Roster::PopulateRoster(const std::string dataArr[], size_t size){
    
    
    for (size_t i = 0; i < size; ++i) {
        std::string individualStudent = dataArr[i];
        std::string studentID, firstName, lastName, emailAddress;
        int age, daysInCourse1, daysInCourse2, daysInCourse3;
        DegreeProgram degreeProgram;
        
        // find first comma and get studentID
        size_t firstCommaLoc = individualStudent.find(",");
        studentID = individualStudent.substr(0, firstCommaLoc);
        
        // find second comma and get firstName;
        size_t secondCommaLoc = individualStudent.find(",", firstCommaLoc + 1);
        firstName = individualStudent.substr(firstCommaLoc + 1, secondCommaLoc - firstCommaLoc - 1);
        
        // find third comma and get lastName;
        size_t thirdCommaLoc = individualStudent.find(",", secondCommaLoc + 1);
        lastName = individualStudent.substr(secondCommaLoc + 1, thirdCommaLoc - secondCommaLoc - 1);
        
        // find fourth comma and get emailAddress
        size_t fourthCommaLoc = individualStudent.find(",", thirdCommaLoc + 1);
        emailAddress = individualStudent.substr(thirdCommaLoc + 1, fourthCommaLoc - thirdCommaLoc - 1);
        
        // find fifth comma and get age
        size_t fifthCommaLoc = individualStudent.find(",", fourthCommaLoc + 1);
        age = std::stoi(individualStudent.substr(fourthCommaLoc + 1, fifthCommaLoc - fourthCommaLoc - 1));
        
        size_t sixthCommaLoc = individualStudent.find(",", fifthCommaLoc + 1);
        daysInCourse1 = std::stoi(individualStudent.substr(fifthCommaLoc + 1, sixthCommaLoc - fifthCommaLoc - 1));
        
        size_t seventhCommaLoc = individualStudent.find(",", sixthCommaLoc + 1);
        daysInCourse2 = std::stoi(individualStudent.substr(sixthCommaLoc + 1, seventhCommaLoc - sixthCommaLoc - 1));
        
        size_t eighthCommaLoc = individualStudent.find(",", seventhCommaLoc + 1);
        daysInCourse3 = std::stoi(individualStudent.substr(seventhCommaLoc + 1, eighthCommaLoc - seventhCommaLoc - 1));
        
        // STRING TO ENUM
        std::string degreeString;
        degreeString = individualStudent.substr(eighthCommaLoc + 1);
        degreeProgram = strToEnum(degreeString);
        
        // create student objects
        int* daysInCourseArr = new int[3];
        daysInCourseArr[0] = daysInCourse1;
        daysInCourseArr[1] = daysInCourse2;
        daysInCourseArr[2] = daysInCourse3;
        Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArr, degreeProgram);
        
//        ***Print student for testing purposes
//        std::cout << newStudent->GetStudentID() << " " << newStudent->GetFirstName() << " " << newStudent->GetLastName() << " "
//        << newStudent->GetEmailAddress() << " " << newStudent->GetAge() << " " << newStudent->GetDaysInCourse() << " " << newStudent->GetDegreeProgram() << std::endl;
        this->classRosterArray[i] = newStudent;
    }
    
}
