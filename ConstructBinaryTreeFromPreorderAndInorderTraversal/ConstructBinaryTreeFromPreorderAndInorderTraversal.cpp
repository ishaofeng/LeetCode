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
    typedef vector<int>::iterator VIT;
public:
    TreeNode *buildTreeHelp(VIT ps, VIT pe, VIT is, VIT ie)
    {
        int len = pe - ps;
        if (len <= 0)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(*ps);
        if (len != 1)
        {
            VIT mid = find(is, ie, *ps);
            assert(mid != ie);

            int lchild = mid - is;
            root->left = buildTreeHelp(ps + 1, ps + 1 + lchild, is, mid);
            root->right = buildTreeHelp(ps + 1 + lchild, pe, mid + 1, ie);
        }

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeHelp(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};
