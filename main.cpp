/*
Gaurav Singh
gs6nv@umsystem.edu
*/

#include <iostream>
#include <string>
#include "ExpressionMan.h"
#include "Queue.h"

using namespace std;

int main() {
    // Q1: Infix to Postfix Conversion
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    // Balanced Parentheses Check
    if (!ExpressionManager::isBalanced(infixExpression)) {
        cout << "Invalid expression. Unbalanced parentheses.\n";
    } else {
        string postfixExpression = ExpressionManager::infixToPostfix(infixExpression);
        cout << "Postfix expression: " << postfixExpression << endl;
    }

    // Q2: Queue Operations
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.getFront() << endl;
    cout << "Queue size: " << queue.size() << endl;

    cout << "Dequeued element: " << queue.dequeue() << endl;
    cout << "Front element: " << queue.getFront() << endl;
    cout << "Queue size: " << queue.size() << endl;

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}