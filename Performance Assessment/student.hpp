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
    // Getters
    std::string GetStudentID() const;
    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetEmailAddress() const;
    int GetAge() const;
    int GetDaysInCourse() const;
    DegreeProgram GetDegreeProgram() const;
    
    // Setters
    std::string SetStudentID(std::string studentID);
    std::string SetFirstName(std::string firstName);
    std::string SetLastName(std::string lastName);
    int SetAge(int age);
    int SetDaysInCourse(int daysInCourse[]);
    DegreeProgram SetDegreeProgram(DegreeProgram degreeProgram);
    
    
};

#endif /* student_hpp */
