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
    int height(TreeNode *root)
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
    
    void levelOrderHelp(TreeNode *root, int level, int countlevel, vector<int> &line)
    {
        if (root == NULL)
        {
            return ;
        }
        if (level == countlevel)
        {
            line.push_back(root->val);
        }
        else
        {
            levelOrderHelp(root->left, level, countlevel + 1, line);
            levelOrderHelp(root->right, level, countlevel + 1, line);
        }
    }
    
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root != NULL)
        {
            int h = height(root);
            for (int i = 0; i < h; ++i)
            {
                vector<int> line;
                levelOrderHelp(root, i, 0, line);
                result.push_back(line);
            }
        }
        
        return result;
    }
};
