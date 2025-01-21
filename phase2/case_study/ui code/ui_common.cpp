#include "ui_common.h"

void UICommon::TitleBar(const std::string& title) {
    std::cout << "\n========================\n";
    std::cout << title << "\n";
    std::cout << "========================\n";
}

void UICommon::PressAnyKey(bool clearScreen) {
    std::cout << "\nPress any key to continue...";
    std::cin.ignore();
    std::cin.get();

    if (clearScreen) {
        std::cout << "\033[2J\033[1;1H"; // Clear screen (works in most terminals)
    }
}