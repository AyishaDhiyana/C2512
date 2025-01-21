#ifndef UI_COMMON_H
#define UI_COMMON_H

#include <iostream>
#include <string>
#include <limits>

class UICommon {
public:
    struct Input {
        std::string Str(const std::string& prompt) {
            std::string input;
            std::cout << prompt << " ";
            std::getline(std::cin, input);
            return input;
        }

        int Int(const std::string& prompt) {
            int input;
            while (true) {
                std::cout << prompt << " ";
                std::cin >> input;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number.\n";
                } else {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
            }
            return input;
        }

        bool exist() {
            // Dummy function to simulate email existence check
            return false; // Replace with actual logic if needed
        }
    };

    Input in;

    void TitleBar(const std::string& title) {
        std::cout << "\n============================\n";
        std::cout << title << "\n";
        std::cout << "============================\n";
    }

    void Line(char c) {
        std::cout << std::string(30, c) << "\n";
    }

    void PressAnyKey(bool pause = true) {
        if (pause) {
            std::cout << "Press Enter to continue...";
            std::cin.get();
        }
    }
};

extern UICommon uiCommon;

#endif // UI_COMMON_H