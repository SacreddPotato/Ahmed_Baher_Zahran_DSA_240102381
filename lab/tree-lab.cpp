#include <iostream>

using namespace std;

struct Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int x) {
            this->data = x;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class BST {
    private:
        Node* root;

    public: 
        BST() {
            this->root = nullptr;
        }

        Node* insert(Node* r, int val) {
           if (r == nullptr) {
                r = new Node(val);
           }

           if (val <= r->data) {
               r->left = insert(r->left, val);
           } else {
               r->right = insert(r->right, val);
           }

           return r;
        }

        void insert(int val) {
            this->root = insert(this->root, val);
        }

        void preOrderTraversal(Node* root) {
            if (root == nullptr) {
                return;
            }

            cout << root->data << "\n";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }

        void inOrderTraversal(Node* root) {
            if (root == nullptr) {
                return;
            }

            inOrderTraversal(root->left);
            cout << root->data << "\n";
            inOrderTraversal(root->right);
        }

        void postOrderTraversal(Node* root) {
            if (root == nullptr) {
                return;
            }

            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->data << "\n";
        }

        
};