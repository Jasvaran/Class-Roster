//
//  main.cpp
//  Performance Assessment
//
//  Created by Jasvaran Mann on 3/6/25.
//

#include <iostream>
#include "student.hpp"
#include "degree.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    const std::string studentData[] =

    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE"
    };
    
    int* arr = new int[3]{1, 2, 3};
    DegreeProgram testDegree = DegreeProgram::SECURITY;
    Student* myStudent = new Student("A1","jesse", "mann", "jasvm@gmail.com", 31,arr,testDegree);
    
    std::cout << myStudent->GetDaysInCourse();
    
    return 0;
}
