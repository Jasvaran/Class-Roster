//
//  roster.hpp
//  Performance Assessment
//
//  Created by Jasvaran Mann on 3/6/25.
//

#ifndef roster_hpp
#define roster_hpp

#include <iostream>
#include "student.hpp"
class Roster {
//    instance variables
    Student** classRosterArray;
    int classRosterSize = 5;
    int rosterCounter = 0;

    
public:
//    member functions
    Roster();
    ~Roster(){
        for (size_t i = 0; i < rosterCounter; ++i){
            delete classRosterArray;
        }
    };
    
    void PopulateRoster(const std::string dataArr[], size_t size);
    void Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void Remove(std::string studentID);
    void PrintAll();
    void PrintAverageDaysInCourse(std::string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degreeProgram);
    void resizeRoster();
    int returnRosterSize();
    Student** accessClassRosterArr();
    DegreeProgram strToEnum(std::string& str);
};



#endif
