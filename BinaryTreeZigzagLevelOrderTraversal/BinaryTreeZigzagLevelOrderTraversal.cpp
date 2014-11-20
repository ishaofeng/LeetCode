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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int> > result;
        if (root == NULL)
        {
            return result;
        }

        stack<TreeNode *> s1, s2;
        TreeNode *cur;

        s1.push(root);
        while (!(s1.empty() && s2.empty()))
        {
            vector<int> line;
            if (s1.empty())
            {
                while (!s2.empty())
                {
                    cur = s2.top();
                    s2.pop();
                    line.push_back(cur->val);

                    if (cur->left != NULL)
                    {
                        s1.push(cur->left);
                    }

                    if (cur->right != NULL)
                    {
                        s1.push(cur->right);
                    }
                }
            }
            else
            {
                while (!s1.empty())
                {
                    cur = s1.top();
                    s1.pop();
                    line.push_back(cur->val);
                    if (cur->right != NULL)
                    {
                        s2.push(cur->right);
                    }

                    if (cur->left != NULL)
                    {
                        s2.push(cur->left);
                    }
                }
            }
            result.push_back(line);
        }

        return result;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);

    vector<vector<int> > result = s.zigzagLevelOrder(root);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[0].size(); ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
