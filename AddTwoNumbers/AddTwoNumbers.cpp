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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL || l2 == NULL)
        {
            return NULL;
        }

        ListNode head(0);
        ListNode *tail = &head;

        int sum, sub = 0;
        ListNode *newnode;
        while (l1 != NULL && l2 != NULL)
        {
            sum = l1->val + l2->val + sub;
            sub = sum / 10;
            sum = sum % 10;

            newnode = new ListNode(sum);
            tail->next = newnode;
            tail = tail->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {
            sum = l1->val + sub;
            sub = sum / 10;
            sum = sum % 10;

            newnode = new ListNode(sum);
            tail->next = newnode;
            tail = tail->next;

            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            sum = l2->val + sub;
            sub = sum / 10;
            sum = sum % 10;

            newnode = new ListNode(sum);
            tail->next = newnode;
            tail = tail->next;

            l2 = l2->next;
        }

        if (sub != 0)
        {
            tail->next = new ListNode(sum);
            tail = tail->next;
        }
        tail->next = NULL;

        return head.next;
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
