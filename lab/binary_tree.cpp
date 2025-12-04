struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int x) {
        this->val = x;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
};



class BinaryTree {
    private:
        Node* root;
    
    public:
        BinaryTree() {
            this->root = nullptr;
        }

        
};