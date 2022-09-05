#ifndef MENU_H
#define MENU_H

#include <string>
#include <functional>
#include <vector>

struct choice {
    std::string prompt;
    std::function<void(void)> action;
};

class Menu {
    private:
        std::string title;
        std::vector<choice> choices;
    public:
        Menu(std::string title, std::vector<choice> choices): title(title), choices(choices) {}
        void draw();
};

#endif
