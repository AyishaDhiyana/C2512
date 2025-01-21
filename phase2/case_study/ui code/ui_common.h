#ifndef UI_COMMON_H
#define UI_COMMON_H

#include <iostream>
#include <string>

class UICommon {
public:
    void TitleBar(const std::string& title);
    void PressAnyKey(bool clearScreen = false);
};

#endif