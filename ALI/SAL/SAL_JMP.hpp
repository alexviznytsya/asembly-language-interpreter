//
//  SAL_JMP.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_JMP_h
#define SAL_JMP_h

#include "SAL.hpp"
#include "../CPU/ALI_CPU.hpp"

class SAL_JMP: public SAL {
    private:
        uint8_t value;
        ALI_CPU* cpu;
    
    protected:
    
    public:
        SAL_JMP(uint8_t, ALI_CPU*);
        ~SAL_JMP();
        void execute();
        std::string toString();
};

#endif /* SAL_JMP_h */
