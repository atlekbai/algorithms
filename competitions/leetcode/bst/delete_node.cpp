#include <iostream>
#include <list>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printStack(std::list<TreeNode*> const &stack) {
    for (auto &el: stack) {
        std::cout << el->val << ",";
    }
    std::cout << std::endl;
}

class Solution {
private:
    std::list<TreeNode*> stack;
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) {
                delete root;
                return (NULL);
            }
            else if (!root->left || !root->right) {
                TreeNode *tmp = (root->left ? root->left : root->right);
                delete root;
                return (tmp);
            }
            else {
                TreeNode *tmp = root->right;
                while (tmp->left)
                    tmp = tmp->left;
                root->val = tmp->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return (root);
    }
};

int main(void)
{
    TreeNode *start = new TreeNode(0);
    Solution solution;
    solution.deleteNode(start, 0);
    std::cout << start << " " << start->val << std::endl;
    return (0);
}