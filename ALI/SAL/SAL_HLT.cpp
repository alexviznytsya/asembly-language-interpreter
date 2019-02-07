//
//  SAL_HLT.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "SAL_HLT.hpp"

// Private methods:

// Protected methods:

// Public methods:

// Default constructor:
SAL_HLT::SAL_HLT(ALI_CPU* c) : cpu{c} {}

// Default destructor:
SAL_HLT::~SAL_HLT() {
    
}

// Execute command:
void SAL_HLT::execute() {
    this->cpu->HLT();
}

// Print SAL instruction:
std::string SAL_HLT::toString() {
    return "HLT ";
}

