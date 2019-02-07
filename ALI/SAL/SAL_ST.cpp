//
//  SAL_ST.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "SAL_ST.hpp"

// Private methods:

// Protected methods:

// Public methods:

// Default constructor:
SAL_ST::SAL_ST(std::string s, ALI_CPU* c) : symbol{s}, cpu{c} {}

// Default destructor:
SAL_ST::~SAL_ST() {}

// Execute command:
void SAL_ST::execute() {
    this->cpu->ST(this->symbol);
}

// Print SAL instruction:
std::string SAL_ST::toString() {
    return "ST " + this->symbol;
}

