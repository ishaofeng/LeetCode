#include <iostream>
#include <vector>
#include <set>
#include <cctype>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <limits>
#include <algorithm>
#include <list>
#include <utility>
#include <cstdlib>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if  (root != NULL)
        {
            stack<TreeNode *> s;
            bool bDone = false;

            TreeNode *cur = root;
            while (!bDone)
            {
                if (cur != NULL)
                {
                    if (cur->right != NULL)
                    {
                        s.push(cur->right);
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
                        if (cur->right != NULL && !s.empty() && cur->right == s.top())
                        {
                            TreeNode *right = s.top();
                            s.pop();

                            s.push(cur);

                            cur = right;
                        }
                        else
                        {
                            result.push_back(cur->val);
                            cur = NULL;
                        }
                    }
                    else
                    {
                        bDone = true;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->left->left = new TreeNode(9);
    vector<int> r = s.postorderTraversal(root);
    for (int i = 0; i < r.size(); ++i)
    {
        cout << r[i] << " ";
    }
    cout << endl;
    vector<vector<int> > result;
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[0].size(); ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
