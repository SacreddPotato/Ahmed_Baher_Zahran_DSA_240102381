#include <vector>

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        this->queue = vector<int>(k);
        this->numOfElements = 0; 
        this->queueSize = k;
        this->head = 0;
        this->tail = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        queue[tail++] = value;
        numOfElements ++;
        if (tail == queueSize) {
            tail = 0;
        }

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        head++;
        numOfElements --;
        if (head == queueSize) {
            head = 0;
        }
    
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return queue[head];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        if (tail == 0) {
            return queue[queueSize - 1];
        }
        return queue[tail - 1];
    }
    
    bool isEmpty() {
        return (head == tail && numOfElements == 0);
    }
    
    bool isFull() {
        return (head == tail && numOfElements == queueSize);
    }

    private:
    vector<int> queue;
    int numOfElements;
    int queueSize;
    int head;
    int tail;
};


