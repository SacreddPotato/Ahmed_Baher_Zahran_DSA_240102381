#include <iostream>

using namespace std;

class Stack {
    public:
    int stack[6];
    int pointer;

    Stack() {
        this->pointer = -1;
    }

    void put(int x) {
        if (this->pointer == 5) {
            cout << "Stack is full\n";
            return;
        }
        stack[++this->pointer] = x;
        return;
    }

    int pop() {
        if (this->pointer == -1) {
            cout << "Stack is empty\n";
            return -99;
        } 
        return stack[this->pointer--];
    }

    int getTopValue() {
        return stack[this->pointer];
    }

};

class Queue {
    private:
    bool isEmpty() {
        return (this->tail == this->head && this->elementCounter == 0);
    }

    bool isFull() {
        return (this->tail == this->head && this->elementCounter == 6);
    }
    public:
    int queue[6];
    int tail;
    int head;
    int elementCounter;

    Queue() {
        this->tail = 0;
        this->head = 0;
        this->elementCounter =0;
    }

    void enqueue(int x) {
        if (this->tail + 1 > 6) {
            this->tail = 0;
        }
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        elementCounter ++;
        queue[this->tail++] = x;
    }

    int dequeue() {
        if (this->head + 1 > 6) {
            this->head = 0;
        }
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -99;
        }
        if (this->head + 1 > 6) {
            this->head = 0;
        }
        elementCounter --;
        return queue[this->head++];
    }

    int getQueuedTerm() {
        return queue[this->head];
    }

};

int main() {
    Stack s;
    s.put(1);
    s.put(2);
    s.put(3);
    s.put(4);
    s.put(5);
    s.put(6);
    s.put(1); // Should Return full stack
    int x = s.pop();
    cout << "Popped Element: " << x << "\n";
    x = s.pop();
    cout << "Popped Element: " << x << "\n";
    x = s.pop();
    cout << "Popped Element: " << x << "\n";
    x = s.pop();
    cout << "Popped Element: " << x << "\n";
    x = s.pop();
    cout << "Popped Element: " << x << "\n";
    x = s.pop();
    cout << "Popped Element: " << x << "\n";
    x = s.pop(); //Should Return empty stack

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(1); // Should return full queue
    x = q.dequeue();
    cout << "Dequeued element: " << x << "\n";
    q.enqueue(7);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue(); // Empty

    return 0;
}