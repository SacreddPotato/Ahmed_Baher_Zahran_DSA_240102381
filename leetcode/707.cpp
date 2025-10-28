class Node { 
    public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;  

    MyLinkedList() {
        this->head = nullptr;
    }
    
    int get(int index) {
        if (head == nullptr) {
            return -1;
        }
        if (index == 0) {
            return head->val;
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            if (current->next == nullptr) {
                return -1;
            }
            current = current->next;
        }

        return current->val;
    }
    
    void addAtHead(int val) {
        if (head == nullptr) {
            head = new Node(val);
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        if (head == nullptr) {
            head = new Node(val);
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (head == nullptr) {
            return;
        }

        Node* previous = head;
        for (int i = 0; i < index - 1; i++) {
            if (previous->next == nullptr) {
                return;
            }
            previous = previous->next;
        }
        
        Node* newNode = new Node(val);
        newNode->next = previous->next;
        previous->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        if (head == nullptr) {
            return;
        }
        if (index == 0) {
            head = head->next;
            return;
        }

        Node* previous = head;
        for (int i = 0; i < index - 1; i++) {
            if (previous->next == nullptr) {
                return;
            }
            previous = previous->next;
        }
        if (previous->next == nullptr) {
            return;
        }
        previous->next = previous->next->next;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */