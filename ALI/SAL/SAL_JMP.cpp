//
//  SAL_JMP.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "SAL_JMP.hpp"

// Private methods:

// Protected methods:

// Public methods:

// Default constructor:
SAL_JMP::SAL_JMP(uint8_t v, ALI_CPU* c) : value{v}, cpu{c} {}

// Default destructor:
SAL_JMP::~SAL_JMP() {}

// Execute command:
void SAL_JMP::execute() {
    this->cpu->JMP(this->value);
}

// Print SAL instruction:
std::string SAL_JMP::toString() {
    return "JMP " + std::to_string(this->value);
}
