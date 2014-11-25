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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        if (root == NULL)
        {
            return result;
        }
        
        TreeNode *cur = root;
        stack<TreeNode *> s;
        vector<int> v;
        bool bDone = false;
        int nsum = 0;
        while (!bDone)
        {
            if (cur != NULL)
            {
                if (cur->right != NULL)
                {
                    s.push(cur->right);
                }
                
                nsum += cur->val;
                v.push_back(cur->val);
                if (cur->left == NULL && cur->right == NULL && nsum == sum)
                {
                    result.push_back(v);
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
                    nsum -= cur->val;
                    v.pop_back();
                    if (!s.empty() && cur->right != NULL && cur->right == s.top())
                    {
                        TreeNode *right = s.top();
                        s.pop();
                        
                        nsum += cur->val;
                        v.push_back(cur->val);
                        s.push(cur);
                        
                        cur = right;
                    }
                    else
                    {
                        cur = NULL;
                    }
                }
                else
                {
                    bDone = true;
                }
            }
        }
        return result;
    }
};
