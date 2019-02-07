//
//  SAL_CPU.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "ALI_CPU.hpp"
#include "../ALI.hpp"
#include "../SAL/SAL_VALUE.hpp"

ALI_CPU::ALI_CPU(std::vector<SAL*>* m) : mainMemory{m}, symbolTable(){
    this->registerA = 0;
    this->registerB = 0;
    this->pc = 0;
    this->prevPc = 0;
    this->hBit = false;
    this->zBit = false;
    this->oBit = false;
}

ALI_CPU::~ALI_CPU() {
    
}

void ALI_CPU::DEC(std::string s) {
    this->symbolTable.insert(std::make_pair(s, this->pc));
    delete (*this->mainMemory)[this->pc];
    (*this->mainMemory)[this->pc] = new SAL_VALUE("DEC " + s, this);
    this->prevPc = this->pc;
    this->pc++;
}

void ALI_CPU::LDA(std::string s) {
    unsigned int pos = this->symbolTable[s];
    SAL* sal_value = (*this->mainMemory)[pos];
    this->registerA = (uint32_t)stoul(sal_value->toString());
    this->prevPc = this->pc;
    this->pc++;
}

void ALI_CPU::LDB(std::string s) {
    unsigned int pos = this->symbolTable[s];
    SAL* sal_value = (*this->mainMemory)[pos];
    this->registerB = (uint32_t)stoul(sal_value->toString());
    this->prevPc = this->pc;
    this->pc++;
}
void ALI_CPU::LDI(uint32_t v) {
    this->registerA = v;
    this->prevPc = this->pc;
    this->pc++;
}
void ALI_CPU::ST(std::string s) {
    unsigned int pos = this->symbolTable[s];
    SAL* sal_value = (*this->mainMemory)[pos];
    delete sal_value;
    (*this->mainMemory)[pos] = new SAL_VALUE(std::to_string((int32_t)this->registerA), this);
    this->prevPc = this->pc;
    this->pc++;
}
void ALI_CPU::XCH() {
    uint32_t t = this->registerA;
    this->registerA = this->registerB;
    this->registerB = t;
    this->prevPc = this->pc;
    this->pc++;
}
void ALI_CPU::JMP(uint8_t v) {
    if(this->isAddressValid(v)) {
        this->prevPc = this->pc;
        this->pc = v;
    } else {
        this->hBit = true;
    }
}
void ALI_CPU::JZS(uint8_t v) {
    if(this->isAddressValid(v)) {
        if(this->zBit) {
            this->prevPc = this->pc;
            this->pc = v;
        } else {
            this->prevPc = this->pc;
            this->pc++;
        }
    } else {
        this->hBit = true;
    }
}
void ALI_CPU::JVS(uint8_t v) {
    if(this->isAddressValid(v)) {
        if(this->oBit) {
            this->prevPc = this->pc;
            this->pc = v;
        } else {
            this->prevPc = this->pc;
            this->pc++;
        }
    } else {
        this->hBit = true;
    }
}
void ALI_CPU::ADD() {
    this->oBit = false;
    this->zBit = false;
    
    unsigned long sum = this->registerA + this->registerB;
    
    if(sum == 0) {
        this->zBit = true;
    }
    
    if((this->registerA < 2147483648 && this->registerB < 2147483648) && sum > 2147483647) {
        this->oBit = true;
    } else if((this->registerA > 2147483647 && this->registerB > 2147483647) && sum < 2147483648){
        this->oBit = true;
    } else if(sum > 4294967296l) {
        sum = sum - 4294967296;
    }
    this->registerA = (uint32_t)sum;
    this->prevPc = this->pc;
    this->pc++;
}

void ALI_CPU::HLT() {
    this->hBit = true;
    this->prevPc = this->pc;
    this->pc++;
}

bool ALI_CPU::isAddressValid(uint8_t a) {
    if (a >= ALI::MEMORY_SIZE || a >= (*(this->mainMemory)).size()) {
        return false;
    } else {
        return true;
    }
}

void ALI_CPU::reset() {
    this->prevPc = 0;
    this->pc = 0;
    this->hBit = false;
    this->oBit = false;
    this->zBit = false;
    this->registerA = 0;
    this->registerB = 0;
    for(uint32_t i = 0; i < this->mainMemory->size(); i++) {
        delete (*this->mainMemory)[i];
    }
    this->mainMemory->clear();
    this->symbolTable.clear();
}

bool ALI_CPU::isHalted() {
    return this->hBit;
}

void ALI_CPU::executeInstruction() {
    (*this->mainMemory)[this->pc]->execute();
}

void ALI_CPU::getState(std::vector<std::string>& v) {
    v.push_back(std::to_string(this->pc));
    v.push_back(std::to_string((int32_t)this->registerA));
    v.push_back(std::to_string((int32_t)this->registerB));
    v.push_back(this->oBit ? "1" : "0");
    v.push_back(this->zBit ? "1" : "0");
}


