#include <iostream>
#include <vector>
#include <algorithm>
#include <assert>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int balancedHeight(TreeNode *root, bool &result)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        
        int lh = balancedHeight(root->left, result);
        int lr = balancedHeight(root->right, result);
        if (result == false || abs(lh - lr) >= 2)
        {
            result = false;
        }
        
        return max(lh, lr) + 1;
    }
    bool isBalanced(TreeNode *root) {
        bool result = true;
        balancedHeight(root, result);
        
        return result;
    }
};
