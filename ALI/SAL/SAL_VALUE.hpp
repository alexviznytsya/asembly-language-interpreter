//
//  SAL_VALUE.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_VALUE_h
#define SAL_VALUE_h

#include "SAL.hpp"
#include "../CPU/ALI_CPU.hpp"

class SAL_VALUE : public SAL {
    private:
        ALI_CPU* cpu;
        std::string value;
    protected:
    
    public:
        SAL_VALUE(std::string, ALI_CPU*);
        ~SAL_VALUE();
        void execute();
        std::string toString();
};

#endif /* SAL_VALUE_h */
