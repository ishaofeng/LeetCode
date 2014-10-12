#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> l;

        if (root != NULL) {
            stack<TreeNode *> s;
            TreeNode *node = NULL, *lastnode = NULL;

            s.push(root);
            while (s.empty() == false) {
                node = s.top();
                s.pop();

                l.push_back(node->val);

                if (node->right != NULL) {
                    s.push(node->right);
                }

                if (node->left != NULL) {
                    s.push(node->left);
                }
            }
        }

        return l;
    }
};

int main() {

    return 0;
}
