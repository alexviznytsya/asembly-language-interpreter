//
//  SAL_Command.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_h
#define SAL_h

#include <iostream>
#include <string>

enum SAL_INSTRUCTION : int {
    DEC = 1, LDA, LDB, LDI, ST, XCH, JMP, JZS, JVS, ADD, HLT
};

class SAL {
    private:
    
    protected:
    
    public:
        virtual ~SAL()=0;
        virtual void execute()=0;
        virtual std::string toString()=0;
};

#endif /* SAL__h */
