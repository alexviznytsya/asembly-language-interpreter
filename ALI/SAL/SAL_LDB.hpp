//
//  SAL_LDB.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef SAL_LDB_h
#define SAL_LDB_h

#include "SAL.hpp"
#include "../CPU/ALI_CPU.hpp"

class SAL_LDB: public SAL {
    private:
        std::string symbol;
        ALI_CPU* cpu;
    
    protected:
    
    public:
        SAL_LDB(std::string, ALI_CPU*);
        ~SAL_LDB();
        void execute();
        std::string toString();

};

#endif /* SAL_LDB_h */
