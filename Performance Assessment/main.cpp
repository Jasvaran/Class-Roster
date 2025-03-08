//
//  main.cpp
//  Performance Assessment
//
//  Created by Jasvaran Mann on 3/6/25.
//

#include <iostream>
#include "student.hpp"
#include "degree.hpp"
#include "roster.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
      const std::string studentData[] =

    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Jasvaran,Mann,jasvaranm@gmail.com,31,25,50,65,SOFTWARE"
    };
    
    int studentDataSize = sizeof(studentData) / sizeof(studentData[0]);
    
//    int* arr = new int[3]{1, 2, 3};
//    int* newArr = new int[3]{3, 2, 1};
//    DegreeProgram testDegree = DegreeProgram::SECURITY;
//    Student* myStudent = new Student("A1","jesse", "mann", "jasvm@gmail.com", 31,arr,testDegree);
//    
//    myStudent->GetDaysInCourse();
//    myStudent->SetDaysInCourse(newArr);
//    myStudent->GetDaysInCourse();
//    
    Roster* myRoster = new Roster();
    myRoster->PopulateRoster(studentData, studentDataSize);
    
    
    return 0;
}
