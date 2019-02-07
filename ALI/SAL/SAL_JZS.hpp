//
//  SAL_JZS.hpp
//  avizny2_project4
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_JZS_h
#define SAL_JZS_h

#include "SAL.hpp"
#include "../CPU/ALI_CPU.hpp"

class SAL_JZS: public SAL {
    private:
        uint8_t value;
        ALI_CPU* cpu;
    
    protected:
    
    public:
        SAL_JZS(uint8_t, ALI_CPU*);
        ~SAL_JZS();
        void execute();
        std::string toString();
    
};

#endif /* SAL_JZS_h */
