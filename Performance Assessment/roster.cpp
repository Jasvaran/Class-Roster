//
//  roster.cpp
//  Performance Assessment
//
//  Created by Jasvaran Mann on 3/6/25.
//

#include "roster.hpp"
#include <iostream>
#include <string>

Roster::Roster(){};
void Roster::PopulateRoster(const std::string dataArr[], size_t size){
    
    for (size_t i = 0; i < size; ++i) {
        std::string individualStudent = dataArr[i];
        size_t firstCommaLoc = individualStudent.find(",");
        
        std::cout << individualStudent << std::endl;
        
        
    }
    
}
