#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct StackNode {
    StackNode* next;
    char val;
    StackNode(char x) {
        this->val = x;
        this->next = nullptr;
    }
};

class Stack {
    private:
        StackNode* top;
        int numOfElements;
    public:
        Stack() {
            this->top = nullptr;
        }

        void push(int x) {
            if (this->top == nullptr) {
                this->top = new StackNode(x);
                return;
            }

            StackNode* newNode = new StackNode(x);
            newNode->next = this->top;
            this->top = newNode;
        }

        char pop() {
            if (this->top == nullptr) {
                cout << "Stack is empty!\n";
                return ' ';
            }

            StackNode* temp = this->top;
            int val = temp->val;
            this->top = this->top->next;
            delete temp;
            return val;
        }

        char peek() {
            if (this->top == nullptr) {
                cout << "Stack is empty!\n";
                return ' ';
            }

            return this->top->val;            
        }

        bool isEmpty() {
            return this->top == nullptr;
        }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string expression) {
    Stack operators;
    string postfix = "";

    for (char ch: expression) {
        if (ch == ' ') {
            continue;
        }

        if (isalnum(ch)) {
            postfix += ch;

        } else if (ch == '(') {
            postfix += ' ';
            operators.push(ch);

        } else if (ch == ')') {
            postfix += ' ';
            while (!operators.isEmpty() || operators.peek() != '(') {
                postfix += operators.pop();
            }
            operators.pop();

        } else {
            postfix += ' ';
            while(!operators.isEmpty() && precedence(operators.peek()) >= precedence(ch)) {
                postfix += operators.pop();
                postfix += ' ';
            }
            operators.push(ch);
        }
    }

    postfix += ' ';
    while (!operators.isEmpty()) {
        postfix += operators.pop();
    }

    return postfix;
}

int evaluatePostfix(string expression) {
    Stack values;

    for (char ch: expression) {
        if (ch == ' ') {
            continue;
        }

        if (isalnum(ch)) {
            values.push(ch - '0');

        } else {
            int val2 = values.pop();
            int val1 = values.pop();
            int result = 0;

            switch (ch) {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    result = val1 / val2;
                    break;
            }

            values.push(result);
        }
    }

    return values.pop();
}


int main() {
    cout << evaluatePostfix(infixToPostfix("3 + 4 * 7"));
    return 0;
}