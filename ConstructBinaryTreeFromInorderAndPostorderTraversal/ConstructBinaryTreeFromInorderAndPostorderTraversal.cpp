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
    TreeNode *buildTreeHelp(VIE is, VIE ie, VIE ps, VIE pe)
    {
        int len = ie - is;
        if (len <= 0)
        {
            return NULL;
        }
        
        TreeNode *root = new TreeNode(*(pe - 1));
        if (len > 1)
        {
            VIE mid = find(is, ie, root->val);
            assert(mid != ie);
            
            int lchild = mid - is;
            root->left = buildTreeHelp(is, mid, ps, ps + lchild);
            root->right = buildTreeHelp(mid + 1, ie, ps + lchild, pe - 1);
        }
        
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeHelp(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};
