#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> list;
        return dfs(root, list);
    }

    vector<int> dfs(TreeNode* root, vector<int> list) {
        if (root == nullptr) {
            return list;
        }

        list = dfs(root->left, list);
        list = dfs(root->right, list);
        list.push_back(root->val);

        return list;
    }
};