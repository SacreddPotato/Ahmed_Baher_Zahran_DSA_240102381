#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) {
        this->val = x;
        this->next = nullptr;
    }
};

class LinkedList {
    private:
    Node* head;
    int numOfElements;  
    
    public:
        LinkedList() {
            this->head = nullptr;
            this->numOfElements = -1;
        }

        void add(int x) {
            Node* newNode = new Node(x);
            if (this->head == nullptr) {
                this->head = newNode;
                numOfElements ++;
                return;
            }

            Node* prev = this->head;
            while (prev->next != nullptr) {
                prev = prev->next;
            }

            prev->next = newNode;
            numOfElements ++;
        }

        void addAtIndex(int index, int x) {
            if (index > numOfElements + 1 || index < 0) {
                cout << "Index out of bounds!\n";
                return;
            }
            Node* newNode = new Node(x);
            if (index == 0) {
                newNode->next = this->head;
                this->head = newNode;
                numOfElements++;
                return;
            }

            Node* prevNode = this->head;
            for (int i = 0; i < index - 1; i++) {
                prevNode = prevNode->next;
            }

            newNode->next = prevNode->next;
            prevNode->next = newNode;
            numOfElements++;
        }

        void addAfterFirstOfValue(int insertionVal, int comparedVal) {
            Node* prev = head;
            Node* newNode = new Node(insertionVal);
            if (prev->val == comparedVal) {
                newNode->next = prev->next;
                prev->next = newNode;
                return;
            }

            while (prev->next != nullptr) {
                if (prev->val == comparedVal) {
                    newNode->next = prev->next;
                    prev->next = newNode;
                    numOfElements++;
                    return;
                }

                prev = prev->next;
            }

            cout << "No value of " << comparedVal << " found\n";
        }

        void popAtEnd() {
            Node* temp;
            if (this->head == nullptr) {
                cout << "List is Empty!\n";
                return;
            }

            if (this->head->next == nullptr) {
                temp = this->head->next;
                this->head = nullptr;
                delete temp;
                numOfElements--;
                return;
            }

            Node* prevNode = this->head;
            while (prevNode->next->next != nullptr) {
                prevNode = prevNode->next;
            }
            temp = prevNode->next;
            prevNode->next = nullptr;
            delete temp;
            numOfElements--;
        }

        void popAtIndex(int index) {
            Node* temp;
            if (index > numOfElements || index < 0) {
                cout << "Index out of bounds!\n";
                return;
            }
            
            if (index == 0) {
                temp = this->head;
                this->head = this->head->next;
                delete temp;
                numOfElements--;
                return;

            }
            Node* prevNode = this->head;

            for (int i = 0; i < index - 1; i++) {
                prevNode = prevNode->next;
            }
            temp = prevNode->next;
            prevNode->next = prevNode->next->next;
            delete temp;
            numOfElements--;
        }

        void popFirstOfValue(int x) {     
            Node* temp;       
            if (this->head->val == x) {
                temp = this->head;
                this->head = this->head->next;
                delete temp;
                numOfElements--;
                return;
            }

            Node* prev = this->head;
            do {
                if (prev->next->val == x) {
                    temp = prev->next;
                    prev->next = prev->next->next;
                    delete temp;
                    numOfElements--;
                    return;
                }

                prev = prev->next;
            } while (prev->next != nullptr);

            cout << "Value: " << x << " not found.\n";
        }
        
        void popAllOfValue(int x) {      
            Node* temp;
            int counter = 0;
            while (this->head->val == x && this->head != nullptr) {
                this->head = this->head->next;
                numOfElements--;
                counter++;
            }

            Node* prev = this->head;
            do {
                if (prev->next->val == x) {
                    temp = prev->next;
                    prev->next = prev->next->next;
                    delete temp;
                    numOfElements--;
                    counter++;
                } else {
                    prev = prev->next;
                }
            } while (prev->next != nullptr);

            if (counter == 0) {
                cout << "No elements deleted\n";
                
            } else {
                cout << counter << " elements deleted\n";
            }
        }

        void popSelection(int startIndx, int endIndx) {
            if (endIndx > numOfElements) {
                return;
            }

            vector<Node*> toBeDeleted;
            Node* curr = this->head;
            Node* startNode;

            for (int i = 0; i <= endIndx; i++) {
                if (i == startIndx - 1) {
                    startNode = curr;
                }
                if (i >= startIndx) {
                    toBeDeleted.push_back(curr);
                }
                curr = curr->next;
            }
            startNode->next = curr;

            delete &toBeDeleted;
        }
        
        int at(int index) {
            if (index > numOfElements || index < 0) {
                cout << "Index out of bounds!\n";
                return -1;
            }
            Node* currNode = this->head;

            for (int i = 0; i < index; i++) {
                currNode = currNode->next;
            }

            return currNode->val;
        }

        int size() {
            return this->numOfElements + 1;
        }

        void printList() {
            if (head == nullptr) {
                cout << "List is empty!";
                return;
            }

            Node* node = this->head;
            int n = 0;
            while (node != nullptr) {
                cout << "Element: " << at(n) << " at index: " << n << "\n";
                node = node->next;
                n++;
            }
            cout << "\n";
        }
};

int main() {
    LinkedList list = LinkedList();
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.printList();
    list.popAtEnd();
    list.printList();
    list.popAtIndex(0);
    list.printList();
    list.add(2);
    list.printList();
    list.addAtIndex(1,5);
    list.printList();
    list.addAtIndex(0,71);
    list.printList();
    cout << list.size() << "\n";
    list.popAllOfValue(71);
    cout << list.size() << "\n";
    list.addAfterFirstOfValue(33,5);
    list.printList();
}