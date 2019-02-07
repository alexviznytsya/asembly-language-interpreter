//
//  ALI_CPU.h
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#pragma once

#ifndef ALI_CPU_h
#define ALI_CPU_h

#include <string>
#include <vector>
#include <map>
#include "../SAL/SAL.hpp"

class ALI_CPU {
    private:
        ALI_CPU(const ALI_CPU &);
        ALI_CPU& operator=(const ALI_CPU &);
        bool isAddressValid(uint8_t);
        std::vector<SAL*>* mainMemory;
        std::map<std::string, unsigned int> symbolTable;
        uint32_t registerA;
        uint32_t registerB;
        uint8_t pc;
        uint8_t prevPc;
        bool hBit;
        bool zBit;
        bool oBit;

    protected:
    
    public:
        ALI_CPU(std::vector<SAL*>*);
        ~ALI_CPU();
        void DEC(std::string);
        void LDA(std::string);
        void LDB(std::string);
        void LDI(uint32_t);
        void ST(std::string);
        void XCH();
        void JMP(uint8_t);
        void JZS(uint8_t);
        void JVS(uint8_t);
        void ADD();
        void HLT();
        void reset();
        bool isHalted();
        void getState(std::vector<std::string>&);
        void executeInstruction();
};

#endif /* ALI_CPU_h */
