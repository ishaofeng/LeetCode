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
    int maxPathSumHelp(TreeNode *root, int &mmax)
    {
        if (root == NULL)
        {
            return 0;
        }
        
        int sl = maxPathSumHelp(root->left, mmax);
        int sr = maxPathSumHelp(root->right, mmax);
 
        mmax = max(max(root->val, mmax), max(sl + root->val, max(sr + root->val, sr + sl + root->val)));
        
        return max(root->val, max(sl, sr) + root->val);
    }
    int maxPathSum(TreeNode *root) {
        int mmax = numeric_limits<int>::lowest();
        maxPathSumHelp(root, mmax);
        
        return mmax;
    }
};
