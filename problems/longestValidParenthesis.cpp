#include <iostream>
#include "stack.hpp"


int getLongestValidParenthesis(const string& expression){
    if (expression.empty() || expression.size()==1)
        return 0;

    Stack<pair<char, int>> stk;
    int size = (int)expression.size();
    for (int i = 0; i < size; i++){
        if (expression[i]=='(')
            stk.push({'(', i});
        else if (expression[i]==')' && !stk.isEmpty() && stk.top().first == '(')
            stk.pop();
        else if (expression[i]==')')
            stk.push({')', i});

    }
    if (stk.isEmpty())
        return (int)expression.size();

    int max, diff;
    // edge case of having a balanced bracket sequence in the very end of the expression
    max = (int)expression.size() - 1 - stk.top().second;

    while (stk.stackSize() > 1){
        diff = stk.pop().second - stk.top().second - 1;
        if (diff > max)
            max = diff;
    }

    // edge case of having a balanced bracket sequence in the very beginning of the expression
    diff = stk.pop().second;
    if (diff > max)
        max = diff;

    return max;
}

int main(){
    string expression;
    cout << "Enter your parenthesis expression:\n";
    getline(cin, expression);
    cout << "Length of longest valid parenthesis is: " << getLongestValidParenthesis(expression) << '\n';
}