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

      const std::string studentData[] =

    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Jasvaran,Mann,jasvaranm@gmail.com,31,25,50,65,SOFTWARE"
    };
    
    // Find size of studentData array.
    int studentDataSize = sizeof(studentData) / sizeof(studentData[0]);
    
    
    std::cout << "C867: Scripting and Programming, C++" << std::endl
                << "Jasvaran Mann" << std::endl
                << "Student ID: 012153087" << std::endl << std::endl;
    
    
    // create and populate roster
    Roster* myRoster = new Roster();
    myRoster->PopulateRoster(studentData, studentDataSize);
    
    //Print All
    myRoster->PrintAll();
    std::cout << std::endl;
    myRoster->PrintInvalidEmails();
    
    // Loop roster
    for (size_t i = 0; i < myRoster->returnRosterSize(); ++i) {
        // call printAvgDaysInCourse, passing the function accessClassRosterArr, which returns a ptr to classRosterArr.
        // Cant access classRosterArray directly through myRoster since it is a private member;
        myRoster->PrintAverageDaysInCourse(myRoster->accessClassRosterArr()[i]->GetStudentID());
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    
    myRoster->PrintByDegreeProgram(DegreeProgram::SOFTWARE);
    myRoster->Remove("A3");
    myRoster->PrintAll();
    myRoster->Remove("A3");
    
    return 0;
}
