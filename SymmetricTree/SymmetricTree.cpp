#include <iostream>
#include <vector>
#include <algorithm>
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
    bool isSymmetricHelp(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
        {
            return true;
        }
        else if (left == NULL || right == NULL)
        {
            return false;
        }
        
        if (left->val != right->val)
        {
            return false;
        }
        
        if (!isSymmetricHelp(left->left, right->right))
        {
            return false;
        }
        
        if (!isSymmetricHelp(left->right, right->left))
        {
            return false;
        }
        
        return true;
    }
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
        {
            return true;
        }
        
        return isSymmetricHelp(root->left, root->right);
    }
};
