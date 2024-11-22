//Main program infix to postfix
#include <iostream>
#include <string>
#include "stack.hpp"
#include "infixToPostfix.hpp"

int main(int argc, char* argv[]) {
    infixToPostfix infixExp;
    std::string infix;

    std::cout << "Enter an infix-formatted expression: " << std::endl;
    if (argc >= 2) {
        // Get the expression from argv instead of from stdin
        for (int i = 1; i < argc; ++i) infix += argv[i];
        std::cout << infix << std::endl;
    } else {
        std::getline(std::cin, infix);
    }

    infixExp.setInfix(infix);
    infixExp.showInfix();
    infixExp.calcPostfix();
    infixExp.showPostfix();
    std::cout << std::endl;
    return 0;
}
