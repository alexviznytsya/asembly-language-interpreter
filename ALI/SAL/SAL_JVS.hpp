//
//  SAL_JVS.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_JVS_h
#define SAL_JVS_h

#include "SAL.hpp"
#include "../CPU/ALI_CPU.hpp"

class SAL_JVS: public SAL {
    private:
        uint8_t value;
        ALI_CPU* cpu;
    
    protected:
    
    public:
        SAL_JVS(uint8_t, ALI_CPU*);
        ~SAL_JVS();
        void execute();
        std::string toString();
};

#endif /* SAL_JVS_h */
