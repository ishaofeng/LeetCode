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

        ListNode *node = head, *prev = NULL, *next;
        bool bDuplicate = false;
        while (node != NULL && node->next != NULL)
        {
            while (node->next != NULL && node->val == node->next->val)
            {
                bDuplicate = true;

                next = node->next;
                node->next = next->next;

                delete next;
            }

            if (bDuplicate == true)
            {
                bDuplicate = false;
                if (prev == NULL)
                {
                    head = node->next;
                }
                else
                {
                    prev->next = node->next;
                }
                next = node->next;
                delete node;
                node = next;
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
