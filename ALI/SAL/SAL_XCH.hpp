//
//  SAL_XCH.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_XCH_h
#define SAL_XCH_h

#include "SAL.hpp"
#include "../CPU/ALI_CPU.hpp"

class SAL_XCH: public SAL {
    private:
        ALI_CPU* cpu;
    
    protected:
    
    public:
        SAL_XCH(ALI_CPU*);
        ~SAL_XCH();
        void execute();
        std::string toString();
};


#endif /* SAL_XCH_h */
