//
//  SAL_LDI.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "SAL_LDI.hpp"

// Private methods:

// Protected methods:

// Public methods:

// Default constructor:
SAL_LDI::SAL_LDI(unsigned int v, ALI_CPU* c) : value{v}, cpu{c} {}

// Default destructor:
SAL_LDI::~SAL_LDI() {}

// Execute command:
void SAL_LDI::execute() {
    this->cpu->LDI(this->value);
}

// Print SAL instruction:
std::string SAL_LDI::toString() {
    return "LDI " + std::to_string((int)this->value);
}
