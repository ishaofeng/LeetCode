#include <iostream>
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
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        } else {
            int ldepth = maxDepth(root->left);
            int rdepth = maxDepth(root->right);

            return 1 + (ldepth < rdepth ? rdepth : ldepth);
        }
    }
};

int main() {

    return 0;
}
