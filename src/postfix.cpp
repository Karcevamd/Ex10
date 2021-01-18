// Copyright 2021 Kartseva Mariya
#include "postfix.h"
#include "MyStack.h"
std::string infix2postfix(std::string inf) {
    inf.push_back(' ');
    MyStack <char> arg(400);
    std::string str;
    char prev = 0;
    std::string ifNum = "1234567890.";
    for (auto i : inf) {
        if (ifNum.find(prev) != std::string::npos &&
            ifNum.find(i) == std::string::npos) {
            str.push_back(' ');
        }
        if (i == '(') {
            arg.push(i);
        } else if (i == ')') {
            while (!arg.isEmpty() &&
                arg.get() != '(') {
                str.push_back(arg.pop());
                str.push_back(' ');
            }
            if (arg.get() == '(') {
                arg.pop();
            }
        } else if (ifNum.find(i) != std::string::npos) {
            str.push_back(i);
        } else if (i == '/' || i == '*') {
            while (!arg.isEmpty() &&
                arg.get() != '(' &&
                arg.get() != '+' &&
                arg.get() != '-') {
                str.push_back(arg.pop());
                str.push_back(' ');
            }
            arg.push(i);
        } else if (i == '+' || i == '-') {
            while (!arg.isEmpty() &&
                arg.get() != '(') {
                str.push_back(arg.pop());
                str.push_back(' ');
            }
            arg.push(i);
        }
        prev = i;
    }
    while (!arg.isEmpty()) {
        str.push_back(arg.pop());
        str.push_back(' ');
    }
    str.pop_back();
    return str;
}
