#include "infixToPostfix.hpp"
#include <iostream>
#include <set>
#include <algorithm>

void infixToPostfix::setInfix(const std::string& infix) {
    this->infix = infix;
    if (infix.back() == ';') this->infix.pop_back();
}

void infixToPostfix::showInfix() const {
    std::cout << infix << std::endl;
}

void infixToPostfix::showPostfix() {
    calcPostfix();
    std::cout << postfix << std::endl;
}

std::vector<Symbol> infixToPostfix::parseEquation(const std::string& equation) {
    std::set<char> openers = {'(', '[', '{'};
    std::set<char> closers = {')', ']', '}'};
    std::set<char> operators = {'+', '-', '*', '/'};

    std::vector<Symbol> symbols;
    for (char c : equation) {
        if (c == ' ') continue;
        else if (std::find(openers.begin(), openers.end(), c) != openers.end()) {
            symbols.push_back({OPENER, std::string() + c});
        } else if (std::find(closers.begin(), closers.end(), c) != closers.end()) {
            symbols.push_back({CLOSER, std::string() + c});
        } else if (std::find(operators.begin(), operators.end(), c) != operators.end()) {
            symbols.push_back({OPERATOR, std::string() + c});
        } else
            symbols.push_back({OPERAND, std::string() + c});
    }

    return symbols;
}

bool infixToPostfix::hasPrecedence(const Symbol& a, const Symbol& b) {
    // returns true if a has precedence over b

    std::set<char> dominant = {'*', '/'};

    // Pseudo:
    // return (a in dominant && b not in dominant)
    
    return (std::find(dominant.begin(), dominant.end(), a.value.c_str()[0]) != dominant.end() && std::find(dominant.begin(), dominant.end(), b.value.c_str()[0]) == dominant.end());
}

void infixToPostfix::calcPostfix() {
    std::vector<Symbol> infix = parseEquation(this->infix);

    postfix = "";
    stack.initializeStack();
    for (Symbol sym : infix) {
        switch (sym.type) {
            case OPERAND:
                postfix += sym.value;
                break;

            case OPENER:
                stack.push(sym);
                break;

            case CLOSER:
                sym = stack.pop();
                while (sym.type != OPENER) {
                    postfix += sym.value;
                    sym = stack.pop();
                }
                break;

            case OPERATOR:
                while (!stack.isEmpty() && stack.top().type != OPENER && !hasPrecedence(sym, stack.top())) {
                    postfix += stack.pop().value;
                }
                stack.push(sym);
                break;
        }
    }
    while (!stack.isEmpty()) postfix += stack.pop().value;
}