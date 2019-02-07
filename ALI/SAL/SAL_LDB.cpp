//
//  SAL_LDB.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "SAL_LDB.hpp"

// Private methods:

// Protected methods:

// Public methods:

// Default constructor:
SAL_LDB::SAL_LDB(std::string s, ALI_CPU* c) : symbol{s}, cpu{c} {}

// Default destructor:
SAL_LDB::~SAL_LDB() {}

// Execute command:
void SAL_LDB::execute() {
    this->cpu->LDB(this->symbol);
}

// Print SAL instruction:
std::string SAL_LDB::toString() {
    return "LDB " + this->symbol;
}

