//
//  student.hpp
//  Performance Assessment
//
//  Created by Jasvaran Mann on 3/6/25.
//

#ifndef student_hpp
#define student_hpp

#include <iostream>
#include <string>
#include "degree.hpp"

class Student {
//    instance variables;
    std::string studentID, firstName, lastName, emailAddress;
    int age;
    int* daysInCourse = new int[3];
    DegreeProgram degreeProgram;
    
    
public:
//    member functions;
    // constructors
    Student();
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram);
    
    // destructor
    ~Student(){
        delete[] daysInCourse;
    };
    
    // Getters
    std::string GetStudentID() const;
    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetEmailAddress() const;
    int GetAge() const;
    std::string GetDaysInCourse() const;
    std::string GetDegreeProgram() const;
    int* GetDaysInCourseArr();
    
    // Setters
    void SetStudentID(std::string studentID);
    void SetFirstName(std::string firstName);
    void SetLastName(std::string lastName);
    void SetEmailAddress(std::string emailAddress);
    void SetAge(int age);
    void SetDaysInCourse(int* daysInCourse);
    void SetDegreeProgram(DegreeProgram degreeProgram);
    
    // Print
    void Print() const;
    
    
};

#endif /* student_hpp */
