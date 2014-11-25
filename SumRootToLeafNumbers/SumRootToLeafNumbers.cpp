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
    int sumNumbers(TreeNode *root) {
        if (root == NULL)
        {
            return 0;
        }
        
        TreeNode *cur = root;
        stack<TreeNode *> s;
        bool bDone = false;
        int total = 0;
        int sum = 0;
        while (!bDone)
        {
            if (cur != NULL)
            {
                if (cur->right != NULL)
                {
                    s.push(cur->right);
                }
                
                sum = sum * 10 + cur->val;
                if (cur->left == NULL && cur->right == NULL)
                {
                    total += sum;
                }
                
                s.push(cur);
                
                cur = cur->left;
            }
            else
            {
                if (!s.empty())
                {
                    cur = s.top();
                    s.pop();
                    sum /= 10;
                    
                    if (!s.empty() && cur->right != NULL && cur->right == s.top())
                    {
                        TreeNode *right = s.top();
                        s.pop();
                        
                        sum = sum * 10 + cur->val;
                        s.push(cur);
                        
                        cur = right;
                    }
                    else 
                    {
                        cur= NULL;
                    }
                }
                else
                {
                    bDone = true;
                }
            }
        }
        return total;
    }
};
