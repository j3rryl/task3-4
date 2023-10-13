#include <iostream>
#include <stack>
#include <string>

int precedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
            return 5;
        case '(':
        case ')':
        case '$':
            return 1;
    }
    return 0;
}

int main() {
    std::string initialExp, finalExp = "";
    std::stack<char> s;
    char symbol;

    std::cout << "Enter expression e.g 9+5*4/2 : ";
    std::cin >> initialExp;

    s.push('$');
    for (auto& ch : initialExp) {
        symbol = ch;

        if (isdigit(symbol)) {
            finalExp += symbol;
        } else if (symbol == '(') {
            s.push(symbol);
        } else if (symbol == ')') {
            while (s.top() != '(') {
                finalExp += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (precedence(s.top()) >= precedence(symbol)) {
                finalExp += s.top();
                s.pop();
            }
            s.push(symbol);
        }
    }

    while (s.top() != '$') {
        finalExp += s.top();
        s.pop();
    }

    std::cout << "Final expression: " << finalExp << std::endl;
    return 0;
}
