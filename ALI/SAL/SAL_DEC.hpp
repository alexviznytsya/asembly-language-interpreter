//
//  SAL_DEC.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_DEC_h
#define SAL_DEC_h

#include "SAL.hpp"
#include "../CPU/ALI_CPU.hpp"

class SAL_DEC: public SAL {
    private:
        std::string symbol;
        ALI_CPU* cpu;
    
    protected:
    
    public:
        SAL_DEC(std::string, ALI_CPU*);
        ~SAL_DEC();
        void execute();
        std::string toString();

};

#endif /* SAL_DEC_h */
