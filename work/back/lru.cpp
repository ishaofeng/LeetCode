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

class LRUCache
{
    struct Node
    {
        int val;
        Node *prev;
        Node *next;
        Node(int val) : val(val), prev(NULL), next(NULL) {}
    };
private:
    Node *head;
    int capacity;
    unordered_map<int, Node *> m;
public:
    LRUCache(int capacity)
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->left->left = new TreeNode(9);
    vector<int> r;
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
