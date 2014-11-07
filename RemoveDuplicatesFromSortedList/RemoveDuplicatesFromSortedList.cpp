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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *node = head->next, *prev = head;
        while (node != NULL)
        {
            if (node->val == prev->val)
            {
                prev->next = node->next;
                delete node;

                node = prev->next;
            }
            else
            {
                prev = node;
                node = node->next;
            }
        }

        return head;
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
    int val[] = {5, 5, 4, 4, 3, 2, 1, 1};
    int len = sizeof(val) / sizeof(val[0]);
    ListNode head(0), *newnode;
    for (int i = 0; i < len; ++i)
    {
        newnode = new ListNode(val[i]);
        newnode->next = head.next;

        head.next = newnode;
    }

    Solution s;
    ListNode *h = s.deleteDuplicates(head.next);
    s.print(h);
    return 0;
}
