#include <iostream>
#include "Menu.h"

using namespace std;

int main(int argc, char **argv){
    Menu main_menu("Main Menu", {
            {"Admin", [](){}},
            {"Employee", [](){}},
            {"Customer", [](){}}
            });

    main_menu.draw();
}

