// Tortoise and Hare algorithm.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}  
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* left = head;
        ListNode* right = head;

        while (right->next != nullptr && right != nullptr) {
            left = left->next;
            right = right->next->next;

            if (left == right) {
                return true;
            }
        }
        return false;
    }
};