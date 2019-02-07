//
//  SAL_ST.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_ST_h
#define SAL_ST_h

#include "SAL.hpp"
#include "../CPU/ALI_CPU.hpp"

class SAL_ST: public SAL {
    private:
        std::string symbol;
        ALI_CPU* cpu;
    
    protected:
    
    public:
        SAL_ST(std::string, ALI_CPU*);
        ~SAL_ST();
        void execute();
        std::string toString();
};


#endif /* SAL_ST_h */
