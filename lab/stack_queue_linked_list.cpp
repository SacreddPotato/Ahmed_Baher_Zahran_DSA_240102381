#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) {
        this->val = x;
        this->next = nullptr;
    }
};

class Stack {
    private:
        Node* top;
    public:
        Stack() {
            this->top = nullptr;
        }

        void push(int x) {
            if (this->top == nullptr) {
                this->top = new Node(x);
                return;
            }

            Node* newNode = new Node(x);
            newNode->next = this->top;
            this->top = newNode;
        }

        int pop() {
            if (this->top == nullptr) {
                cout << "Stack is empty!\n";
                return -1;
            }

            Node* temp = this->top;
            int val = temp->val;
            this->top = this->top->next;
            delete temp;
            return val;
        }

        int peek() {
            if (this->top == nullptr) {
                cout << "Stack is empty!\n";
                return -1;
            }

            return this->top->val;            
        }

        bool isEmpty() {
            return this->top == nullptr;
        }
};

class Queue {
    private:
        Node* front;
        Node* rear;
    public:
        Queue() {
            this->front = nullptr;
            this->rear = nullptr;
        }

        void enqueue(int x) {
            Node* newNode = new Node(x);
            if (this->rear == nullptr) {
                this->front = newNode;
                this->rear = newNode;
                return;
            }

            this->rear->next = newNode;
            this->rear = newNode;
        }

        int dequeue() {
            if (this->front == nullptr) {
                cout << "Queue is empty!\n";
                return -1;
            }

            Node* temp = this->front;
            int val = temp->val;
            this->front = this->front->next;

            if (this->front == nullptr) {
                this->rear = nullptr;
            }

            delete temp;
            return val;
        }

        bool isEmpty() {
            return this->front == nullptr;
        }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    cout << "Stack top: " << stack.peek() << "\n"; 
    cout << "Stack pop: " << stack.pop() << "\n";   
    cout << "Stack pop: " << stack.pop() << "\n";   
    cout << "Is Stack empty? " << stack.isEmpty()  << "\n"; 

    Queue queue;
    queue.enqueue(30);
    queue.enqueue(40);
    cout << "Queue dequeue: " << queue.dequeue() << "\n"; 
    cout << "Queue dequeue: " << queue.dequeue() << "\n"; 
    cout << "Is Queue empty? " << queue.isEmpty() << "\n"; 

    return 0;
}