//
//  SAL_ADD.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_ADD_h
#define SAL_ADD_h

#include "SAL.hpp"
#include "../CPU/ALI_CPU.hpp"

class SAL_ADD: public SAL {
    private:
        ALI_CPU* cpu;
    
    protected:
        
    public:
        SAL_ADD(ALI_CPU*);
        ~SAL_ADD();
        void execute();
        std::string toString();
};

#endif /* SAL_ADD_h */
