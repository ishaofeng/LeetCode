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
    void recoverTree(TreeNode *root) {
        if (root == NULL)
        {
            return ;
        }
        
        stack<TreeNode *> s;
        int max = numeric_limits<int>::lowest();
        TreeNode *cur = root, *prev = NULL;
        bool bDone = false;
        
        vector<pair<TreeNode*, TreeNode *> > infos;
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
                        infos.push_back(make_pair(prev, cur));
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
        
        if (infos.size() == 1)
        {
            swap(infos[0].first->val, infos[0].second->val);
        }
        else if (infos.size() == 2)
        {
            swap(infos[0].first->val, infos[1].second->val);
        }
    }
};
