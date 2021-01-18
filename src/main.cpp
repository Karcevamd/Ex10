// Copyright 2021 Kartseva Mariya
#include "postfix.h"

#include <cstdlib>
#include <iostream>

int main() {
    std::string inf1 = "2 + 2";
    std::string postf1 = infix2postfix(inf1);
    std::string expected1 = "2 2 +";
    if (postf1 == expected1) std::cout << "true 1" << std::endl;

    std::string inf2 = "2 + 6 * 3 / (4 - 2)";
    std::string postf2 = infix2postfix(inf2);
    std::string expected2 = "2 6 3 * 4 2 - / +";
    if (postf2 == expected2) std::cout << "true 2" << std::endl;

    std::string inf3 = "(2 + 8.3) * (6 - 3.2)";
    std::string postf3 = infix2postfix(inf3);
    std::string expected3 = "2 8.3 + 6 3.2 - *";
    if (postf3 == expected3) std::cout << "true 3" << std::endl;

    std::string inf4 = "(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9";
    std::string postf4 = infix2postfix(inf4);
    std::string expected4 = "6 4 2 - * 5 + 2.6 3 7 * + * 9 -";
    if (postf4 == expected4) std::cout << "true 4" << std::endl;
}
