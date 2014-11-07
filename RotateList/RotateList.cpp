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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k <= 0)
        {
            return head;
        }

        int len = 0;
        ListNode *node = head, *prev = NULL;
        while (node != NULL)
        {
            ++len;
            prev = node;
            node = node->next;
        }

        k = k % len;
        if (k == 0)
        {
            return head;
        }


        int off = len - k;
        ListNode *rotateNode = head;
        while (--off > 0)
        {
            rotateNode = rotateNode->next;
        }

        prev->next = head;
        node = rotateNode->next;
        rotateNode->next = NULL;

        return node;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *slow = head, *fast = head;
        while (fast->next != NULL)
        {
            fast = fast->next;
            if (fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }


        ListNode *l2 = slow->next;
        slow->next = NULL;
        ListNode *l1 = head;


        l1 = sortList(l1);
        l2 = sortList(l2);

       return  mergeList(l1, l2);
    }

    ListNode *mergeList(ListNode *l1, ListNode *l2)
    {
        ListNode head(0);
        ListNode *current = &head;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val > l2->val)
            {
                current->next = l2;
                l2 = l2->next;
            }
            else
            {
                current->next = l1;
                l1 = l1->next;
            }
            current = current->next;
        }

        if (l1 == NULL)
        {
            current->next = l2;
        }
        else
        {
            current->next = l1;
        }

        return head.next;
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
    int val[] = {2, 1};
    int len = sizeof(val) / sizeof(val[0]);
    ListNode head(0), *newnode;
    for (int i = 0; i < len; ++i)
    {
        newnode = new ListNode(val[i]);
        newnode->next = head.next;

        head.next = newnode;
    }

    Solution s;
    s.print(s.rotateRight(head.next, 1));
    return 0;
}
