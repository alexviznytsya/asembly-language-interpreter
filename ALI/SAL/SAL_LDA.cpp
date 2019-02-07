//
//  SAL_LDA.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "SAL_LDA.hpp"

// Private methods:

// Protected methods:

// Public methods:

// Default constructor:
SAL_LDA::SAL_LDA(std::string s, ALI_CPU* c) : symbol{s}, cpu{c} {}

// Default destructor:
SAL_LDA::~SAL_LDA() {}

// Execute command:
void SAL_LDA::execute() {
    this->cpu->LDA(this->symbol);
}

// Print SAL instruction:
std::string SAL_LDA::toString() {
    return "LDA " + this->symbol;
}
