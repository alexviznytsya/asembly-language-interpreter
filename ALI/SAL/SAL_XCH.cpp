//
//  SAL_XCH.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "SAL_XCH.hpp"

// Private methods:

// Protected methods:

// Public methods:

// Default constructor:
SAL_XCH::SAL_XCH(ALI_CPU* c) : cpu{c} {}

// Default destructor:
SAL_XCH::~SAL_XCH() {
    
}

// Execute command:
void SAL_XCH::execute() {
    this->cpu->XCH();
}

// Print SAL instruction:
std::string SAL_XCH::toString() {
    return "XCH ";
}
