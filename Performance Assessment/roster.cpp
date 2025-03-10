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


Roster::Roster(){
    classRosterArray = new Student*[classRosterSize];
};

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
//        int* daysInCourseArr = new int[3];
//        daysInCourseArr[0] = daysInCourse1;
//        daysInCourseArr[1] = daysInCourse2;
//        daysInCourseArr[2] = daysInCourse3;
//        Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArr, degreeProgram);
        this->Add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
        
//        this->classRosterArray[i] = newStudent;
//        this->rosterCounter++;


    }
    
}

void Roster::Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    
    
    if (this->rosterCounter == this->classRosterSize) {
        std::cout << "resizing roster prior to adding" << std::endl;
        resizeRoster();

    }
    
    int* daysInCourseArr = new int[3];
    daysInCourseArr[0] = daysInCourse1;
    daysInCourseArr[1] = daysInCourse2;
    daysInCourseArr[2] = daysInCourse3;
    
    
    
    
    // new student dynamically allocates memory and newStudent holds the memory address of the object
    Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArr, degreeProgram);

    
    
 
    this->classRosterArray[rosterCounter] = newStudent;
    this->rosterCounter++;
    
//
  
    
}

void Roster::resizeRoster(){
    int newSize = classRosterSize * 2;
    
    // creating a pointer called newArr thats pointing to an array of student pointers, doubling the size as before.
    Student** newArr = new Student*[classRosterSize];
    
    // copy existing students to new arr;
    for (size_t i = 0; i < rosterCounter; ++i) {
        newArr[i] = classRosterArray[i];
    }
    
    // Here I am deleting the old array from memory;
    delete[] classRosterArray;
    
    //reassigning the classRosterArray pointer to new array of student pointers;
    this->classRosterArray = newArr;
    this->classRosterSize = newSize;
    
    
    
}

void Roster::Remove(std::string studentID){
    
    // find the index of ID we want to remove
    int indexOfID = NULL;
    
    for (int i = 0; i < rosterCounter; ++i){
        if (this->classRosterArray[i]->GetStudentID() == studentID){
            indexOfID = i;
        }

    }
    
    if (!indexOfID){
        std::cout << "Student with id " << studentID << " not found!" << std::endl;
        return;
    }
    
    // loop and remove the item and shift the array to the left.
    if (indexOfID >= 0 && indexOfID < classRosterSize){
        for (int i = indexOfID; i < rosterCounter - 1; ++i){
            classRosterArray[i] = classRosterArray[i + 1];
        }
        this->rosterCounter--;
    }
    
    
}

void Roster::PrintAll(){
    for (size_t i = 0; i < rosterCounter; ++i) {
        this->classRosterArray[i]->Print();
    }
}


void Roster::PrintAverageDaysInCourse(std::string studentID){
    int indexOfStudent = NULL;
    int sum = 0;
    double avg;
    for (int i = 0; i < this->rosterCounter; ++i) {
        if (this->classRosterArray[i]->GetStudentID() == studentID) {
            indexOfStudent = i;
        }
    }
    
    int* daysInCoursePtr2 = classRosterArray[indexOfStudent]->GetDaysInCourseArr();
    
    
    for (size_t i = 0; i < 3; ++i) {
        sum += daysInCoursePtr2[i];
    }
    avg = static_cast<double>(sum) / 3;
    std::cout << avg;
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
    
    for (size_t i = 0; i < rosterCounter; ++i){
        if (this->classRosterArray[i]->GetDegreeProgram() == degreeProgram){
            classRosterArray[i]->Print();
        }
    }
}

void Roster::PrintInvalidEmails(){

    std::string emailAddress;
    std::string afterLastPeriod;
    
    
    

    for (size_t i = 0; i < rosterCounter; ++i){
        emailAddress = classRosterArray[i]->GetEmailAddress();
        if (emailAddress.find(" ") != std::string::npos){
            std::cout << "Invalid email: " << emailAddress << std::endl;
            
        }
        if (emailAddress.find(".") == std::string::npos){
            std::cout << "Invalid email: " << emailAddress << std::endl;
        }
        if (emailAddress.find("@") == std::string::npos){
            std::cout << "Invalid email: " << emailAddress << std::endl;
            
        }
    }
}

int Roster::returnRosterSize(){
    return this->rosterCounter;
}

Student** Roster::accessClassRosterArr(){
    return this->classRosterArray;
}
