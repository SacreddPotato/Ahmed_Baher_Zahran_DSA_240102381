#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev; 
    Node(int x) {
        this->val = x;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
    private:
    Node* head;
    Node* tail;
    int numOfElements;  
    
    public:
        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
            this->numOfElements = 0;
        }

        void add(int x) {
            Node* newNode = new Node(x);
            if (this->head == nullptr) {
                this->head = newNode;
                this->tail = newNode;
                numOfElements ++;
                return;
            }

            Node* current = this->head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
            this->tail = newNode;
            numOfElements++;
        }

        void addAtIndex(int index, int x) {
            if (index < 0 || index >= numOfElements) {
                cout << "Index out of bounds";
                return;
            }
            Node* newNode = new Node(x);
            Node* current = this->head;
            if (index == 0) {
                current->prev = newNode;
                newNode->next = current;
                this->head = newNode;
                numOfElements++;
                return;
            }

            if (index == numOfElements - 1) {
                this->tail->next = newNode;
                newNode->prev = this->tail;
                this->tail = newNode;
                numOfElements++;
                return;
            }

            for (int i = 0; i < index; i++) {
                current = current->next;
            }

            newNode->next = current;
            newNode->prev = current->prev;
            current->prev = newNode;
            newNode->prev->next = newNode;
            numOfElements++;
        }

        void addAfterFirstOfValue(int insertionVal, int comparedVal) {
            if (this->head != nullptr && this->head->val == comparedVal) {
                addAtIndex(0, insertionVal);
                return;
            }

            if (this->tail != nullptr && this->tail->val == comparedVal) {
                addAtIndex(numOfElements - 1, insertionVal);
                return;
            }

            Node* curr = this->head;
            int index = 0;
            bool helper = false;

            while (curr->next != nullptr) {
                if (curr->val == comparedVal) {
                    helper = true;
                    break;
                }
                curr = curr->next;
                index++;
            }

            if (!helper) {
                cout << "Value not found in list";
                return;
            }

            addAtIndex(index + 1, insertionVal);
        }

        void popAtEnd() {
            Node* temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            delete temp;
            numOfElements--;
        }

        void popAtIndex(int index) {
            if (index < 0 || index >= numOfElements) {
                cout << "Index out of bounds";
                return;
            }
            Node* curr = this->head;
            if (index == 0) {
                this->head = this->head->next;
                this->head->prev = nullptr;
                delete curr;
                numOfElements--;
                return;
            }

            if (index == numOfElements - 1) {
                popAtEnd();
                return;
            }

            curr = this->head;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }

            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            numOfElements--;
        }

        int popFirstOfValue(int x) {     
            if (this->head != nullptr && this->head->val == x) {
                popAtIndex(0);
                return 1;
            }

            if (this->tail != nullptr && this->tail->val == x) {
                popAtEnd();
                return 1;
            }

            Node* curr = this->head;
            int index = 0;

            while (curr->next != nullptr) {
                if (curr->val == x) {
                    popAtIndex(index);
                    return 1;
                }
                curr = curr->next;
                index++;
            }
            
            return -1;
        }
        
        int popAllOfValue(int x) {  
            bool helper = false;    
            while (popFirstOfValue(x) != -1) {
                if (!helper) helper = true;
            }

            return (helper) ? 1 : -1;
        }

        void popSelection(int startIndx, int endIndx) {
            Node* beforeSelectionNode = this->head;
            Node* curr = nullptr;

            if (startIndx == 0) {
                beforeSelectionNode = nullptr;
            }

            for (int i = startIndx; i < endIndx; i++) {
                if (beforeSelectionNode != nullptr && i == startIndx) {
                    beforeSelectionNode = at(i-1);
                }

                if (curr == nullptr) {
                    curr = at(i);
                }

                Node* temp = curr;
                curr = curr->next;
                delete temp;
                numOfElements--;
            }

            if (beforeSelectionNode == nullptr) {
                this->head = curr;
                if (this->head != nullptr) {
                    this->head->prev = nullptr;
                }
                return;
            } else {
                beforeSelectionNode->next = curr;
                if (curr != nullptr) {
                    curr->prev = beforeSelectionNode;
                }
                return;
            }
            
        }
        
        Node* at(int index) {
            if (index < 0 || index >= numOfElements) {
                cout << "Index out of bounds";
                return nullptr;
            }

            if (index == 0 && this->head != nullptr) {
                return this->head;
            }

            if (index == numOfElements - 1 && this->tail != nullptr) {
                return this->tail;
            }

            Node* curr = this->head;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }

            return curr;
        }

        int valAtIndex(int index) {
            return at(index)->val;
        }

        int size() {
            return this->numOfElements;
        }

        void printList() {
            Node* curr = this->head;
            while (curr != nullptr) {
                cout << curr->val << "\n";
                curr = curr->next;
            }
            cout << "\n";
        }
};

int main() {
    DoublyLinkedList list = DoublyLinkedList();
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    // list.printList();
    // list.addAtIndex(0,55);
    // list.printList();
    // list.addAtIndex(4,565);
    // list.printList();
    // list.addAfterFirstOfValue(323,2);
    // list.printList();
    // list.addAfterFirstOfValue(789,55);
    // list.printList();
    // list.addAfterFirstOfValue(901,565);
    // list.printList();
    list.add(5);
    list.add(1);
    list.add(1);
    list.add(1);
    list.add(1);
    list.add(1);
    list.add(1);
    list.add(1);
    list.add(1);
    list.printList();
    list.popSelection(1,3);
    list.printList();

    return 0;
}