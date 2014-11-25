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
    void connect(TreeLinkNode *root) {
        if (root == NULL)
        {
            return ;
        }
        
        queue<TreeLinkNode *> q;
        int levelnum = 1;
        int count = 0;
        TreeLinkNode *cur, *prev = NULL;
        q.push(root);
        
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            ++count;
            
            if (cur->left != NULL)
            {
                q.push(cur->left);
            }
            if (cur->right != NULL)
            {
                q.push(cur->right);
            }
            if (prev != NULL)
            {
                prev->next = cur;
            }
            
            prev = cur;
            
            if (count == levelnum)
            {
                levelnum *= 2;
                count = 0;
                prev = NULL;
            }
        }
    }
};
