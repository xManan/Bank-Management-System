#include "Menu.h"
#include <iostream>
#include <limits>

void Menu::draw(){
    unsigned short c;
    while(true){
        std::cout << "\x1b[2J" << "\x1b[H";
        std::cout << "\n\t\t" << title << "\n\n";
        for (int i=0; i<choices.size(); ++i) {
            std::cout << "\t[" << i+1 << "] " << choices[i].prompt << "\n";  
        } 
        std::cout << "\t[" << choices.size()+1 << "] Exit\n";  
        std::cout << std::endl;
        std::cout << "\tEnter your choice: ";
        std::cin >> c;
        std::cin.ignore();
        if(c == choices.size() + 1)
            return;
        if(c > choices.size() + 1){
            std::cout << "\n\tInvalid Choice\n";
            std::cout << "\n\tPress ENTER to continue..." << std::flush;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        choices[c-1].action();
        std::cout << "\n\tPress ENTER to continue..." << std::flush;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         
    }

}
