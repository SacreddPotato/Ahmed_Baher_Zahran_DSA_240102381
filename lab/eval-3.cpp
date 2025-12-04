// MCQ
// Q1
//  1) A
//  2) A
// Q2
//  4)
int countNodes(LinkedList list) {
    Node* curr = list.head;
    int count = 0;

    while (curr->next != nullptr) {
        curr = curr->next;
        count++;
    }

    return count;
} 

//  5)
void reverseNodes(LinkedList list, int firstVal = 2, int endVal = 4) {
    Node* start = nullptr;
    Node* end = nullptr;
    Node* curr = list.head;
    
    while (curr->next != nullptr) {
        if (curr->val == firstVal) {
            start = curr;
        }

        if (curr->val == endVal) {
            end = curr;
        }

        curr = curr->next;
    }

    Node* prev = findPrevNode(start);
    Node* temp = start;
    prev->next = end;
    start->next = end->next;
    end->next = temp->next;
    delete temp;
}

Node* findPrevNode(LinkedList list, Node* node) {
    Node* curr = list.head;

    while (curr->next != nullptr) {
        if (curr->next->val == node->val) {
            return curr;
        }

        curr = curr->next;
    }
}