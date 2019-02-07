//
//  SAL_LDI.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_LDI_h
#define SAL_LDI_h

#include "SAL.hpp"
#include "../CPU/ALI_CPU.hpp"

class SAL_LDI: public SAL {
    private:
        uint32_t value;
        ALI_CPU* cpu;
    
    protected:
    
    public:
        SAL_LDI(unsigned int, ALI_CPU*);
        ~SAL_LDI();
        void execute();
        std::string toString();
};


#endif /* SAL_LDI_h */
