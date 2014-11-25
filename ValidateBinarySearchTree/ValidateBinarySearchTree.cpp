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
    bool isValidBST(TreeNode *root) {
        if (root == NULL)
        {
            return true;
        }
        
        stack<TreeNode *> s;
        int max = numeric_limits<int>::lowest();
        TreeNode *cur = root, *prev = NULL;
        bool bDone = false;
        while (!bDone)
        {
            if (cur != NULL)
            {
                s.push(cur);
                cur = cur->left;
            }
            else
            {
                if (!s.empty())
                {
                    cur = s.top();
                    s.pop();
                    
                    if (prev != NULL && prev->val >= cur->val)
                    {
                        return false;
                    }
                    prev = cur;
                    
                    cur = cur->right;
                }
                else
                {
                    bDone = true;
                }
            }
        }
        return true;
    }
};
