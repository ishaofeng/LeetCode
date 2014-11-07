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
    ListNode *partition(ListNode *head, int x)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *left = NULL, *leftHead = NULL, *right = NULL,  *rightHead = NULL, *node = head;
        while (node != NULL)
        {
            cout << node->val << " " << x << endl;
            if (node->val >= x)
            {
                if (rightHead == NULL)
                {
                    rightHead = node;
                    right = node;
                }
                else
                {
                    right->next = node;
                    right = right->next;
                }
            }
            else
            {
                if (leftHead == NULL)
                {
                    leftHead = node;
                    left = node;
                }
                else
                {
                    left->next = node;
                    left = left->next;
                }
            }

            node = node->next;
        }

        if (leftHead != NULL)
        {
            head = leftHead;
            left->next = rightHead;
        }
        else
        {
            head = rightHead;
        }

        if (rightHead != NULL)
        {
            right->next = NULL;
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
