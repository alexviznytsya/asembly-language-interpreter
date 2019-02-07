//
//  SAL_JVS.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "SAL_JVS.hpp"

// Private methods:

// Protected methods:

// Public methods:

// Default constructor:
SAL_JVS::SAL_JVS(uint8_t v, ALI_CPU* c) : value{v}, cpu{c} {}

// Default destructor:
SAL_JVS::~SAL_JVS() {}

// Execute command:
void SAL_JVS::execute() {
     this->cpu->JVS(this->value);
}

// Print SAL instruction:
std::string SAL_JVS::toString() {
    return "JVS " + std::to_string(this->value);
}

