#include <iostream>
#include <string>

using namespace std;

struct StackNode {
    StackNode* next;
    int val;
    StackNode(int x) {
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
            this->numOfElements = 0;
        }

        void push(int x) {
            if (this->top == nullptr) {
                this->top = new StackNode(x);
                this->numOfElements++;
                return;
            }

            StackNode* newNode = new StackNode(x);
            newNode->next = this->top;
            this->top = newNode;
            this->numOfElements++;
        }

        int pop() {
            if (this->top == nullptr) {
                cout << "Stack is empty!";
                return -99;
            }

            StackNode* temp = this->top;
            int val = temp->val;
            this->top = this->top->next;
            delete temp;
            this->numOfElements--;
            return val;
        }

        int peek() {
            if (this->top == nullptr) {
                cout << "Stack is empty!";
                return -99;
            }

            return this->top->val;            
        }

        string infixToPostfix(string expression) {
            
        }
};