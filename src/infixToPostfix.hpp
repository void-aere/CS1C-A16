#include "stack.hpp"
#include <string>
#include <vector>

enum SymbolType {
    OPENER,     // i.e. (, [, {
    CLOSER,     // i.e. ), ], }
    OPERATOR,   // i.e. +, -, *, /
    OPERAND     // numbers or a variables (multi-character allowed)
};

struct Symbol {
    SymbolType type;
    std::string value;
};

class infixToPostfix {
    private:
        std::string infix;
        std::string postfix;
        linkedStack<Symbol> stack;

        std::vector<Symbol> parseEquation(const std::string& equation);
        bool hasPrecedence(const Symbol& a, const Symbol& b);
    
    public:
        void calcPostfix();
        void setInfix(const std::string& infix);
        std::string getInfix() const;
        std::string getPostfix() const;
};