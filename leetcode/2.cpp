#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        int leftOver = 0;
        bool helper = false;
        
        while (l1 || l2) {
            if (leftOver > 0 && !helper) {
               helper = true;
            }

            if (l1 == nullptr) {
                l1 = new ListNode(0);
            }

            if (l2 == nullptr) {
                l2 = new ListNode(0);
            }

            int res = l1->val + l2->val;
            res += leftOver;
            if (res >= 10) {
                leftOver = res / 10;
                res -= 10;
            }

            if (leftOver > 0 && helper) {
                helper = true;
                if (res >= 10) {
                    leftOver = res / 10;
                    res -= 10;
                } else {
                    helper = false;
                }
            }
            
            if (result == nullptr) {
                result = new ListNode(res);
            } else {
                ListNode* curr = result;
                while (curr->next != nullptr) {
                    curr = curr->next;
                }
                curr->next = new ListNode(res);
            }

            l1 = l1->next;
            l2 = l2->next;
        }


        return result;
    }
};

int main () {
    Solution sol;
    ListNode* l1 = new ListNode(6);
    l1->next = new ListNode(5);
    l1->next->next = new ListNode(8);
    // l1->next->next->next = new ListNode(9);
    // l1->next->next->next->next = new ListNode(9);
    // l1->next->next->next->next->next = new ListNode(9);
    // l1->next->next->next->next->next->next = new ListNode(9);


    ListNode* l2 = new ListNode(8);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(8);
    // l2->next->next->next = new ListNode(9);

    ListNode* result = sol.addTwoNumbers(l1, l2);

    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}