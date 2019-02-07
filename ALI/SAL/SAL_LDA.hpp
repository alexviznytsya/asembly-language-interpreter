//
//  SAL_LDA.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_LDA_h
#define SAL_LDA_h

#include "SAL.hpp"
#include "../CPU/ALI_CPU.hpp"

class SAL_LDA: public SAL {
    private:
        std::string symbol;
        ALI_CPU* cpu;
    
    protected:
    
    public:
        SAL_LDA(std::string, ALI_CPU*);
        ~SAL_LDA();
        void execute();
        std::string toString();
    
};

#endif /* SAL_LDA_h */
