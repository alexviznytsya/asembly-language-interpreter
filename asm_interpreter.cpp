//
//  main.cpp
//
//  Assembly Language Interpreter
//
//  Created by Alex Viznytsya on 5/1/18.
//  Copyright © 2018 Alex Viznytsya. All rights reserved.
//

#include <iostream>
#include <cctype>
#include "ALI/ALI.hpp"

void printHeader() {
    std::cout << "Asembly Language Interpreter" << std::endl;
    std::cout << std::endl;
    std::cout << "Alex Viznytsya" << std::endl;
    std::cout << "05/05/2018" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void printHelp() {
    std::cout << "Asembly Language Interpreter Help:" << std::endl;
    std::cout << std::endl;
    std::cout << "i - This command rads a SAL program from a file" << std::endl;
    std::cout << "    named 'input.sal'. The file should be in the" << std::endl;
    std::cout << "    same directory as your executable ALI file." << std::endl;
    std::cout << std::endl;
    std::cout << "d - Execute the program in debug mode. This command" << std::endl;
    std::cout << "    causes onr line of code to be executed. The PC," << std::endl;
    std::cout << "    registers, bits, and the state of memory are" << std::endl;
    std::cout << "    updated as a result of the execution. The value" << std::endl;
    std::cout << "    of the registers, the PC, the bits and the " << std::endl;
    std::cout << "    content of memory after the instruction is " << std::endl;
    std::cout << "    executed are displayed on the screen." << std::endl;
    std::cout << "    executed are displayed on the screen." << std::endl;
    std::cout << std::endl;
    std::cout << "r - Run the program to completion. This command" << std::endl;
    std::cout << "    causes the execution of program srarting from" << std::endl;
    std::cout << "    the current PC instruction until the halt bit" << std::endl;
    std::cout << "    instruction until is found or the program" << std::endl;
    std::cout << "    reaches its last instruction. The content " << std::endl;
    std::cout << "    of the registers, PC, bits and memory after" << std::endl;
    std::cout << "    instructions is executed are displayed." << std::endl;
    std::cout << std::endl;
    std::cout << "s - Save the program state. This command causes the" << std::endl;
    std::cout << "    content of memory, the bits and the registers" << std::endl;
    std::cout << "    to be saves to a file named 'output.txt'" << std::endl;
    std::cout << std::endl;
    std::cout << "q - Quit the program." << std::endl;
    std::cout << std::endl;
    std::cout << "Please eneter command: > ";
}

int main(int argc, const char * argv[]) {
    ALI ali;
    char command = 0;
    printHeader();
    std::cout << "Welcome to the Asembly Language Interpreter." << std::endl;
    std::cout << std::endl;
    std::cout << "Please eneter command or h for help: > ";
    std::cin >> command;
    while(command != 'q') {
        switch(tolower(command)) {
            case 'h':
                printHelp();
                break;
            case 'i':
                if(ali.loadSALFile("input.sal")) {
                    std::cout << "SAL file has been loaded to the ALI memory." << std::endl;
                    std::cout << std::endl;
                }
                break;
            case 'd':
                if(ali.isReady()) {
                    ali.runOnceWithDebug();
                } else {
                    std::cout << "Load SAL instructios first using 'l' command.";
                    std::cout << std::endl << std::endl;
                }
                break;
            case 'r':
                if(ali.isReady()) {
                    ali.run();
                } else {
                    std::cout << "Load SAL instructios first using 'l' command.";
                    std::cout << std::endl << std::endl;
                }
                break;
            case 's':
                if(ali.isReady()) {
                    ali.saveALIStateToFile("output.txt");
                    std::cout << "CPU and Memory dump has been saveto to 'output.txt'.";
                    std::cout << std::endl << std::endl;
                } else {
                    std::cout << "Load SAL instructios first using 'l' command.";
                    std::cout << std::endl << std::endl;
                }
                break;
            default:
                std::cout << "Error: Invalid command please try again." << std::endl;
        }
        std::cout << "Please eneter command or h for help: > ";
        std::cin >> command;
    }
    std::cout << std::endl;
    std::cout << "Thank you for using this program." << std::endl;
    std::cout << "Exiting program ..." << std::endl;
    return 0;
}
