#include "ExpressionMan.h"
#include <stack>
#include <string>

using namespace std;

// Helper function to check if a character is an opening parenthesis
bool isOpeningParenthesis(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

// Helper function to check if a character is a closing parenthesis
bool isClosingParenthesis(char ch) {
    return ch == ')' || ch == '}' || ch == ']';
}

// Helper function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string ExpressionManager::infixToPostfix(const string& expression) {
    string postfix;
    stack<char> operators;

    for (char ch : expression) {
        if (isOpeningParenthesis(ch)) {
            operators.push(ch);
        } else if (isClosingParenthesis(ch)) {
            while (!operators.empty() && isOpeningParenthesis(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty() && isOpeningParenthesis(operators.top()))
                operators.pop(); // Pop the opening parenthesis
            else {
                // The expression is unbalanced
                return "Invalid expression";
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
            while (!operators.empty() && operators.top() != '(' && operators.top() != '{' && operators.top() != '[' &&
                   getPrecedence(ch) <= getPrecedence(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        } else if (isalnum(ch)) {
            postfix += ch;
        }
    }

    while (!operators.empty()) {
        if (isOpeningParenthesis(operators.top())) {
            // The expression is unbalanced
            return "Invalid expression";
        }
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

bool ExpressionManager::isBalanced(const string& expression) {
    stack<char> parentheses;

    for (char ch : expression) {
        if (isOpeningParenthesis(ch)) {
            parentheses.push(ch);
        } else if (isClosingParenthesis(ch)) {
            if (parentheses.empty()) {
                // Unbalanced closing parenthesis
                return false;
            } else if ((ch == ')' && parentheses.top() != '(') ||
                       (ch == '}' && parentheses.top() != '{') ||
                       (ch == ']' && parentheses.top() != '[')) {
                // Mismatched closing parenthesis
                return false;
            } else {
                parentheses.pop();
            }
        }
    }

    return parentheses.empty();
}