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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode head(0);
        ListNode *node= &head;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val > l2->val)
            {
                node->next = l2;
                l2 = l2->next;
            }
            else
            {
                node->next = l1;
                l1 = l1->next;
            }
            node = node->next;
        }
        while (l1 != NULL)
        {
            node->next = l1;
            l1 = l1->next;
            node = node->next;
        }
        while (l2 != NULL)
        {
            node->next = l2;
            l2 = l2->next;
            node = node->next;
        }

        return node->next;
    }

    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *next = NULL, *node = NULL;

        node = head->next;
        head->next = NULL;

        while (node)
        {
            next = node->next;
            node->next = head;
            head = node;

            node = next;
        }

        return head;
    }

    void print(ListNode *head)
    {
        if ( head != NULL)
        {
            cout << head->val << " ";
            print(head->next);
        }
        else
        {
            cout << endl;
        }
    }

};


int main()
{
    int val[] = {2, 5, 2, 3, 4, 1};
    int len = sizeof(val) / sizeof(val[0]);
    ListNode head(0), *newnode;
    for (int i = 0; i < len; ++i)
    {
        newnode = new ListNode(val[i]);
        newnode->next = head.next;

        head.next = newnode;
    }

    Solution s;
    ListNode *h = s.partition(head.next, 3);
    s.print(h);
    return 0;
}
