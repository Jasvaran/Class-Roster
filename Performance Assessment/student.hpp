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
    int daysInCourse[3];
    DegreeProgram degreeProgram;
    
    
public:
//    member functions;
    // constructors
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram);
    // Getters
    std::string GetStudentID() const;
    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetEmailAddress() const;
    int GetAge() const;
    int* GetDaysInCourse();
    DegreeProgram GetDegreeProgram() const;
    
    // Setters
    void SetStudentID(std::string studentID);
    void SetFirstName(std::string firstName);
    void SetLastName(std::string lastName);
    void SetAge(int age);
    void SetDaysInCourse(int daysInCourse[]);
    void SetDegreeProgram(DegreeProgram degreeProgram);
    
    
};

#endif /* student_hpp */
