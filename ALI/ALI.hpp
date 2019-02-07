//
//  ALI.hpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef ALI_hpp
#define ALI_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CPU/ALI_CPU.hpp"
#include "SAL/SAL.hpp"
#include "SAL/SAL_DEC.hpp"
#include "SAL/SAL_LDA.hpp"
#include "SAL/SAL_LDB.hpp"
#include "SAL/SAL_LDI.hpp"
#include "SAL/SAL_ST.hpp"
#include "SAL/SAL_XCH.hpp"
#include "SAL/SAL_JMP.hpp"
#include "SAL/SAL_JZS.hpp"
#include "SAL/SAL_JVS.hpp"
#include "SAL/SAL_ADD.hpp"
#include "SAL/SAL_HLT.hpp"

class ALI {
    private:
        ALI(const ALI &);
        ALI & operator=(const ALI &);
        SAL* createInstruction(std::string, ALI_CPU*, std::string);
        bool isInstructionValid(std::string);
        std::vector<SAL*> memory;
        ALI_CPU cpu;
        bool ready;
    protected:
    
    public:
        static const uint32_t MEMORY_SIZE;
        ALI();
        ALI(unsigned int memSize);
        ~ALI();
        bool loadSALFile(std::string);
        bool isReady();
        void printCPUState(std::ostream&);
        void printMemoryState(std::ostream&);
        void saveALIStateToFile(std::string);
        void run();
        void runOnceWithDebug();
};

#endif /* ALI_hpp */
