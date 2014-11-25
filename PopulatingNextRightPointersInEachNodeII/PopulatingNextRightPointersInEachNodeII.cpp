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
    int height(TreeLinkNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        
        return max(height(root->left), height(root->right)) + 1;
    }
    
    void connectHelp(TreeLinkNode *root, int level, int countlevel, TreeLinkNode *&prev)
    {
        if (root == NULL)
        {
            return ;
        }
        if (level == countlevel)
        {
            if (prev != NULL)
            {
                prev->next = root;
            }
            prev = root;
        }
        else
        {
            connectHelp(root->left, level, countlevel + 1, prev);
            connectHelp(root->right, level, countlevel + 1, prev);
        }
    }
    
    void connect(TreeLinkNode *root) {
        if (root != NULL)
        {
            int h = height(root);
            for (int i = 0; i < h; ++i)
            {
                TreeLinkNode *prev = NULL;
                connectHelp(root, i, 0, prev);
            }
        }
    }
};
