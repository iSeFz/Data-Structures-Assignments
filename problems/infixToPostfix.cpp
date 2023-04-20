#include <iostream>
#include <algorithm>
#include <string>
#include "stack.hpp"
#include <map>

static std::map<char, int> precedence = {{'^', 1}, {'*', 2}, {'/', 2}, {'+', 3}, {'-', 3}, {'(', 9}, {')', 9}};

std::string infixToPostfix(std::string& infixExp){
    // remove spaces from infixExp
    infixExp.erase(remove(infixExp.begin(), infixExp.end(), ' '), infixExp.end());

    std::string postfixExp;
    Stack<char> operatorStk;
    int size = (int)infixExp.size();

    for (int i = 0; i < size; ++i) {
        // if char is operator
        if (precedence.count(infixExp[i])){
            // removing operators from stack if they have higher precedence than current operator and adding them to
            // postfix exp

            if (infixExp[i]=='('){
                operatorStk.push(infixExp[i]);
                continue;
            }

            if (infixExp[i]==')'){
                // output all operators till the corresponding opening bracket ( in the stack
                while (operatorStk.top()!='('){
                    postfixExp+=operatorStk.pop();
                    postfixExp+=' ';
                }
                operatorStk.pop(); // remove the opening bracket ( from the stack
                continue;
            }

            while(!operatorStk.isEmpty() && precedence[operatorStk.top()] <= precedence[infixExp[i]]){
                postfixExp+=operatorStk.pop();
                postfixExp+=' ';
            }
            operatorStk.push(infixExp[i]);

        } else {
            // else char not operator
            postfixExp+=infixExp[i];
            postfixExp+=' ';
        }
    }
    while (!operatorStk.isEmpty()){
        postfixExp+=operatorStk.pop();
        postfixExp+=' ';
    }
    return postfixExp;
}

int main(){
    std::cout << "Enter your infix expression:\n";
    std::string infixExp;
    getline(std::cin, infixExp);
    std::cout << "Postfix expression: " << infixToPostfix(infixExp) << '\n';
}