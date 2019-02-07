//
//  SAL_VALUE.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "SAL_VALUE.hpp"

SAL_VALUE::SAL_VALUE(std::string s, ALI_CPU* c) : cpu{c}, value{s} {}

SAL_VALUE::~SAL_VALUE() {}

void SAL_VALUE::execute() {
    
}

std::string SAL_VALUE::toString() {
    return this->value;
}

