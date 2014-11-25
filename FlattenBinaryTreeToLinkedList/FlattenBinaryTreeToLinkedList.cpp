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
    void flatten(TreeNode *root) {
        if (root == NULL)
        {
            return ;
        }
        
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *cur, head(0), *tail = &head;
        while (!s.empty())
        {
            cur = s.top();
            s.pop();
            
            if (cur->right != NULL)
            {
                s.push(cur->right);
            }
            if (cur->left != NULL)
            {
                s.push(cur->left);
            }
            tail->right = cur;
            tail = cur;
            tail->left = NULL;
        }
    }
};
