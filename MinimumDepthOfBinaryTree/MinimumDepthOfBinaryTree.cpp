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
    int minDepth(TreeNode *root) {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        
        int dl = minDepth(root->left);
        int dr = minDepth(root->right);
        if (dl == 0)
        {
            return dr + 1;
        }
        else if (dr == 0)
        {
            return dl + 1;
        }
        else
        {
            return min(dl, dr) + 1;
        }
    }
};
