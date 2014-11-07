#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        TreeNode *root = NULL;
        if (head->next == NULL)
        {
            root = new TreeNode(head->val);
            return root;
        }

        ListNode *slow = head, *fast = head, *prev = NULL;
        while (fast->next != NULL)
        {
            fast = fast->next;
            if (fast->next != NULL)
            {
                fast = fast->next;
                prev = slow;
                slow = slow->next;
            }
        }

        root = new TreeNode(slow->val);
        if (prev != NULL)
        {
            prev->next = NULL;
            root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(slow->next);

        return root;
    }
};


int main()
{
    Solution s;
    vector<ListNode*> lists;
    ListNode*a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);

    s.sortedListToBST(a);
    return 0;
}
