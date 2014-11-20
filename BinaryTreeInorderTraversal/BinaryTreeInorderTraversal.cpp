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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root != NULL)
        {
            TreeNode *current = root;
            bool bDone = false;
            stack<TreeNode *> s;

            while (!bDone)
            {
                if (current != NULL)
                {
                    s.push(current);
                    current = current->left;
                }
                else
                {
                    if (!s.empty())
                    {
                        current = s.top();
                        s.pop();
                        result.push_back(current->val);

                        current = current->right;
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
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(7);

    Solution s;
    vector<int> v =  s.inorderTraversal(root);
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
