//
//  SAL_JZS.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "SAL_JZS.hpp"

// Private methods:

// Protected methods:

// Public methods:

// Default constructor:
SAL_JZS::SAL_JZS(uint8_t v, ALI_CPU* c) : value{v}, cpu{c} {}

// Default destructor:
SAL_JZS::~SAL_JZS() {}

// Execute command:
void SAL_JZS::execute() {
     this->cpu->JZS(this->value);
}

// Print SAL instruction:
std::string SAL_JZS::toString() {
    return "JZS " + std::to_string(this->value);
}

