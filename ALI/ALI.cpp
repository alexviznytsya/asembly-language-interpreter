//
//  ALI.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include "ALI.hpp"
#include <chrono>
#include <ctime>

const unsigned int ALI::MEMORY_SIZE = 256;

// Private methods defenitions:
SAL* ALI::createInstruction(std::string inst, ALI_CPU* cpu, std::string instVal = "") {
    if(inst == "DEC") {
        return new SAL_DEC(instVal, cpu);
    } else if(inst == "LDA") {
        return new SAL_LDA(instVal, cpu);
    } else if(inst == "LDB") {
        return new SAL_LDB(instVal, cpu);
    } else if(inst == "LDI") {
        return new SAL_LDI(std::stoi(instVal), cpu);
    } else if(inst == "ST") {
        return new SAL_ST(instVal, cpu);
    } else if(inst == "XCH") {
        return new SAL_XCH(cpu);
    } else if(inst == "JMP") {
        return new SAL_JMP(std::stoi(instVal), cpu);
    } else if(inst == "JZS") {
        return new SAL_JZS(std::stoi(instVal), cpu);
    } else if(inst == "JVS") {
        return new SAL_JVS(std::stoi(instVal), cpu);
    } else if(inst == "ADD") {
        return new SAL_ADD(cpu);
    } else if(inst == "HLT") {
        return new SAL_HLT(cpu);
    }
    return nullptr;
}

bool ALI::isInstructionValid(std::string inst) {
    if(inst == "DEC") {
        return true;
    } else if(inst == "LDA") {
        return true;
    } else if(inst == "LDB") {
       return true;
    } else if(inst == "LDI") {
        return true;
    } else if(inst == "ST") {
        return true;
    } else if(inst == "XCH") {
        return true;
    } else if(inst == "JMP") {
        return true;
    } else if(inst == "JZS") {
       return true;
    } else if(inst == "JVS") {
        return true;
    } else if(inst == "ADD") {
       return true;
    } else if(inst == "HLT") {
        return true;
    } else {
        return false;
    }
}
// Protected methods defenitions:

// Public methods defenitions:

// Default constructor:
ALI::ALI() : memory(), cpu(&memory), ready{false} {};

//Default Descturtor
ALI::~ALI() {
    for(uint32_t i = 0; i < this->memory.size(); i++) {
        if(this->memory[i] != nullptr) {
            delete this->memory[i];
        }
    }
}

// Load SAL instruction from file to memory:
bool ALI::loadSALFile(std::string fn) {
    
    // Method variables:
    std::string fileLine = "";
    uint32_t numOfFileLines = 1;
    
    // Clean CPU flags:
    this->cpu.reset();
    
    // Try to open passed file for reading:
    std::ifstream file(fn, std::ifstream::in);
    
    // Check if file exists:
    if(file.good() != true) {
        std::cerr << "Error: Cannot find '" << fn <<"' file." << std::endl;
        std::cout << std::endl;
        return false;
    }
    
    // Load SAL instructions to the memory:
    while(std::getline(file,fileLine)) {
        std::size_t delimeterPos = 0;
        std::string instruction = "";
        std::string instValue = "";
        
        // Check memory capacity:
        if(numOfFileLines > ALI::MEMORY_SIZE) {
            std::cout << "Error: Memory is full. Cannot load more instructions";
            std::cout << std::endl;
            return false;
        }
        
        // Skip empty lines:
        if(fileLine.length() == 0) {
            numOfFileLines++;
            continue;
        }
        
        // Check for valid instructions:
        if(fileLine.length() < 2) {
            std::cerr << "Error: Incorrect instruction:"<< std::endl;
            std::cerr << "       Line " << numOfFileLines << ": ";
            std::cerr << fileLine << std::endl;
            std::cout << std::endl;
            return false;
        }
        
        // Parse valid instructions:
        
        if(fileLine.length() >= 2) {
            if((delimeterPos = fileLine.find(" ")) != std::string::npos) {
                instruction = fileLine.substr(0, delimeterPos);
                std::string subLine = fileLine.substr(delimeterPos + 1);
                if((delimeterPos = subLine.find(" ")) == std::string::npos) {
                    instValue = subLine;
                } else {
                    std::cerr << "Error: Incorrect instruction:"<< std::endl;
                    std::cerr << "       Line " << numOfFileLines << ": ";
                    std::cerr << fileLine << std::endl;
                    std::cout << std::endl;
                    return false;
                }
                this->memory.push_back(this->createInstruction(instruction, &this->cpu, instValue));
            } else if(this->isInstructionValid(fileLine)) {
                this->memory.push_back(this->createInstruction(fileLine, &this->cpu));
            } else {
                std::cerr << "Error: Incorrect instruction:"<< std::endl;
                std::cerr << "       Line " << numOfFileLines << ": ";
                std::cerr << fileLine << std::endl;
                std::cout << std::endl;
                return false;
            }
        }
        numOfFileLines++;
    }
    file.close();
    this->ready = true;
    return true;
}

void ALI::saveALIStateToFile(std::string fn) {
    
    // Open file for write
    std::ofstream file(fn, std::ofstream::out | std::ofstream::trunc);
    
    // Create file time stamp:
    auto timeNow = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(timeNow);
    file << "ALI CPU and Memory dump created on: ";
    file << std::ctime(&end_time) << std::endl << std::endl;
    
    // Read CPU state:
    std::vector<std::string> cpuState;
    this->cpu.getState(cpuState);
    
    this->printCPUState(file);
    this->printMemoryState(file);

    file.flush();
    file.close();
}

bool ALI::isReady() {
    return this->ready;
}

//
// cpuState vector structure:
//    [0] -> PC
//    [1] -> RegisterA
//    [2] -> RegisterB
//    [3] -> Overflow Bit
//    [4] -> Zero Bit
//
void ALI::printCPUState(std::ostream& stream) {
    char stringBuffer[81];
    std::vector<std::string> cpuState;
    this->cpu.getState(cpuState);
    stream << "Content of CPU memory:" << std::endl;
    std::sprintf(stringBuffer, "%-16s", "    PC:");
    stream << stringBuffer;
    stream << " " << cpuState[0] << std::endl;
    std::sprintf(stringBuffer, "%-16s", "    Register A:");
    stream << stringBuffer;
    std::sprintf(stringBuffer, " %-16s", (cpuState[1]).c_str());
    stream << stringBuffer;
    std::sprintf(stringBuffer, "%-17s", "    Overflow Bit:");
    stream << stringBuffer;
    std::sprintf(stringBuffer, " %-5s", (cpuState[3]).c_str());
    stream << stringBuffer;
    stream << std::endl;
    std::sprintf(stringBuffer, "%-16s", "    Register B:");
    stream << stringBuffer;
    std::sprintf(stringBuffer," %-16s", (cpuState[2]).c_str());
    stream << stringBuffer;
    std::sprintf(stringBuffer,"%-17s", "    Zero Bit:");
    stream << stringBuffer;
    std::sprintf(stringBuffer," %-5s", (cpuState[4]).c_str());
    stream << stringBuffer;
    stream << std::endl << std::endl;
}

void ALI::printMemoryState(std::ostream& stream) {
    char stringBuffer[81];
    stream << "Content of 256 words memory:" << std::endl;
    sprintf(stringBuffer, "%-20s", "    Address:");
    stream << stringBuffer;
    sprintf(stringBuffer, "%-15s", "Instruction:");
    stream << stringBuffer << std::endl;
    uint32_t i = 0;
    for(; i < this->memory.size(); i++) {
        sprintf(stringBuffer, "%-20s", ("       " + std::to_string(i)).c_str());
        stream << stringBuffer;
        sprintf(stringBuffer,"%-15s", ("    " + this->memory[i]->toString()).c_str());
        stream << stringBuffer;
        stream << std::endl;
    }
    stream << std::endl << "***The rest " << 256 - i;
    stream << " instructions are empty." << std::endl<< std::endl;
}

void ALI::run() {
    while(!this->cpu.isHalted()) {
        this->cpu.executeInstruction();
    }
    this->printCPUState(std::cout);
    this->printMemoryState(std::cout);
}

void ALI::runOnceWithDebug() {
    if(!this->cpu.isHalted()) {
        this->cpu.executeInstruction();
        this->printCPUState(std::cout);
        this->printMemoryState(std::cout);
    } else {
        this->printCPUState(std::cout);
        this->printMemoryState(std::cout);
    }
}
