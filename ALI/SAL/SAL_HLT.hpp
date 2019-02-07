//
//  SAL_HLT.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_HLT_h
#define SAL_HLT_h

#include "SAL.hpp"
#include "../CPU/ALI_CPU.hpp"

class SAL_HLT: public SAL {
    private:
        ALI_CPU* cpu;
    
    protected:
    
    public:
        SAL_HLT(ALI_CPU*);
        ~SAL_HLT();
        void execute();
        std::string toString();
    
};

#endif /* SAL_HLT_h */
