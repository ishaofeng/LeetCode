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
    ListNode *reverseBetween1(ListNode *head, int m, int n)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        int count = 1;
        ListNode *node = head, *prev= NULL, *phead = NULL, *next;
        while (count <= n && node != NULL)
        {
            if (count > m)
            {
                next = node->next;
                node->next = phead->next;

                phead->next = node;

                prev->next = next;

                node = next;
            }
            else
            {
                if ((count + 1) == m)
                {
                    phead = node;
                }
                prev = node;
                node = node->next;
            }

            ++count;
        }

        return head;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        reverseBetweenHelp(head, m, n, 1);
        return head;

    }

    ListNode *reverseBetweenHelp(ListNode *&head, int m, int n, int count)
    {
        if (head->next != NULL && count < n)
        {
            ListNode *ret = reverseBetweenHelp(head->next, m, n, count + 1);
            if (count < m)
            {
                return NULL;
            }
            else
            {
                ListNode *next = ret->next;
                ret->next = head;
                head = head->next;
                ret->next->next = next;
                return ret->next;
            }
        }
        else
        {
            if (count == n)
            {
                return head;
            }
        }
        return NULL;
    }


    void print(ListNode *head)
    {
        if (head != NULL)
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
    int val[] = {5, 4, 3, 2, 1};
    int len = sizeof(val) / sizeof(val[0]);
    ListNode head(0), *newnode;
    for (int i = 0; i < len; ++i)
    {
        newnode = new ListNode(val[i]);
        newnode->next = head.next;

        head.next = newnode;
    }

    Solution s;
    s.print(s.reverseBetween1(head.next, 2, 4));
    return 0;
}
