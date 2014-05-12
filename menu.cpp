#include "menu.h"


void Menu::operator()() {
    int selection = -1;
    while (selection != 0) {
        std::cout << title << "\n";
        std::cout << "0. Return\n";
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << (i+1) << ". " << items[i].first << "\n";
        }
        std::cout << ">> ";

        std::cin >> selection;
        std::cin.clear();
        std::cout << "\n";
        if (selection > 0 && selection <= static_cast<int>(items.size())){
            items[selection - 1].second();
        }
    }
}
