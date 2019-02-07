//
//  SAL_DEC.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "SAL_DEC.hpp"

// Private methods:

// Protected methods:

// Public methods:

// Default constructor:
SAL_DEC::SAL_DEC(std::string s, ALI_CPU* c) : symbol{s}, cpu{c} {}

// Default destructor:
SAL_DEC::~SAL_DEC() {}

// Execute command:
void SAL_DEC::execute() {
    this->cpu->DEC(this->symbol);
}

// Print SAL instruction:
std::string SAL_DEC::toString() {
    return "DEC " + this->symbol;
}
