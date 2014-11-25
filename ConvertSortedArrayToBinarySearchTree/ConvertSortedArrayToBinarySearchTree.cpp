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
    typedef vector<int>::iterator VIE;
public:
    TreeNode *sortedArrayToBST(VIE s, VIE e)
    {
        int len = e - s;
        if (len <= 0)
        {
            return NULL;
        }
        
        if (len == 1)
        {
            return new TreeNode(*s);
        }
        
        VIE mid = s + (len >> 1);
        TreeNode *root = new  TreeNode(*mid);
        root->left = sortedArrayToBST(s, mid);
        root->right = sortedArrayToBST(mid + 1, e);
        
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num.begin(), num.end());
    }
};
