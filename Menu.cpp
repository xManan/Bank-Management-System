#include "Menu.h"
#include <iostream>
#include <limits>

void Menu::draw(){
    unsigned short c;
    while(true){
        // clear screen and move cursor to 1:1 position
        std::cout << "\x1b[2J" << "\x1b[H";
        std::cout << "\n\t\t" << title << "\n\n";

        // iterate over choices and print them
        for (int i=0; i<choices.size(); ++i) {
            std::cout << "\t[" << i+1 << "] " << choices[i].prompt << "\n";  
        } 

        // exit choice for every menu
        std::cout << "\t[" << choices.size()+1 << "] Exit\n";  
        std::cout << std::endl;
        std::cout << "\tEnter your choice <1-" << choices.size()+1 << ">: ";
        std::cin >> c;
        // clear \n character from input buffer
        std::cin.ignore();

        // if chose exit return from the draw function
        if(c == choices.size() + 1)
            return;

        // for invalid choice
        if(c > choices.size() + 1){
            std::cout << "\n\tInvalid Choice\n";
            std::cout << "\n\tPress ENTER to continue..." << std::flush;
            // ignore all input or if input is a \n
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if(choices[c-1].action())
            continue;
        std::cout << "\n\tPress ENTER to continue..." << std::flush;
            // ignore all input or if input is a \n
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         
    }

}
