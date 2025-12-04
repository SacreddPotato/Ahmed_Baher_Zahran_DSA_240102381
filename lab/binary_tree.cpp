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

        void add(int x) {
            if (this->root == nullptr) {
                this->root = new Node(x);
                return;
            }

            Node* parent = this->root;
            while (true) {
                if (x <= parent->val) {
                    if (parent->left == nullptr) {
                        parent->left = new Node(x);
                        parent->left->parent = parent;
                        return;
                    } else {
                        parent = parent->left;
                    }
                } else if (x > parent->val) {
                    if (parent->right == nullptr) {
                        parent->right = new Node(x);
                        parent->right->parent = parent;
                        return;
                    } else {
                        parent = parent->right;
                    }
                }
            }
        }

        Node* findPredecessor(Node* node) {
            // If the node has a left subtree, find its maximum value.
            if (node->left != nullptr) {
                Node* curr = node->left;
                while (curr->right != nullptr) {
                    curr = curr->right;
                }

                return curr;
            }

            // Else, find rightenmost ancestor
            Node* curr = node;
            while (curr->parent != nullptr && curr == curr->parent->left) {
                curr = curr->parent;
            }

            return curr->parent;
        }

        Node* findAncestor(Node* node) {
            // If the node has a right subtree, find it's minimum value
            if (node->right != nullptr) {
                Node* curr = node->right;
                while (curr->left != nullptr) {
                    curr = curr->left;
                }

                return curr;
            }

            //Else, find the leftenmost ancestor
            Node* curr = node;
            while (curr->parent != nullptr && curr->parent->right == curr) {
                curr = curr->parent;
            }

            return curr->parent;
        }

        Node* findNode(int x) {
            if (this->root == nullptr) {
                return nullptr;
            }

            Node* curr = this->root;
            while (true) {
                if (x < curr->val) {
                    if (curr->left == nullptr) {
                        return nullptr;
                    }   
                    curr = curr->left;
                } else if (x > curr->val) {
                    if (curr->right == nullptr) {
                        return nullptr;
                    }
                    curr = curr->right;
                } else {
                    return curr;
                }
            }
        }

        void deleteNode(int val) {
            Node* toBeDeleted = findNode(val);

            if (toBeDeleted->left == nullptr && toBeDeleted->right == nullptr) {
                if (toBeDeleted->parent == nullptr) {
                    this->root = nullptr;
                
                } else if (toBeDeleted->parent->left == toBeDeleted) {
                    toBeDeleted->parent->left = nullptr;

                } else {
                    toBeDeleted->parent->right = nullptr;
                }

                delete toBeDeleted;
                return;
            }

            if (toBeDeleted->left == nullptr || toBeDeleted->right == nullptr) {
                Node* child = (toBeDeleted->left != nullptr) ? toBeDeleted->left : toBeDeleted->right;

                if (toBeDeleted->parent == nullptr) {
                    this->root = child;
                } else if (toBeDeleted->parent->left == toBeDeleted) {
                    toBeDeleted->parent->left = child;
                } else {
                    toBeDeleted->parent->right = child;
                }

                delete toBeDeleted;
                return;
            }

            Node* predecessor = findPredecessor(toBeDeleted);
            if (predecessor != nullptr) {
                toBeDeleted->val = predecessor->val;
                if (predecessor->parent->left == predecessor) {
                    predecessor->parent->left = predecessor->left;
                } else {
                    predecessor->parent->right = predecessor->left;
                }

                delete predecessor;
            }            
        }
};