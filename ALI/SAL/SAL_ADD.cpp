//
//  SAL_ADD.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "SAL_ADD.hpp"

// Private methods:

// Protected methods:

// Public methods:

// Default constructor:
SAL_ADD::SAL_ADD(ALI_CPU* c) : cpu{c} {}

// Default destructor:
SAL_ADD::~SAL_ADD() {}

// Execute command:
void SAL_ADD::execute() {
    this->cpu->ADD();
}

// Print SAL instruction:
std::string SAL_ADD::toString() {
    return "ADD ";
}

