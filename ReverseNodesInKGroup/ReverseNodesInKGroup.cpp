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
    ListNode *reverseGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        reverseGroupHelp(head, k, 1);
        return head;

    }

    ListNode *reverseGroupHelp(ListNode *&head, int k, int count)
    {
        if (head->next != NULL)
        {
            ListNode *ret = reverseGroupHelp(head->next, k, count + 1);
            if (count % k == 0)
            {
                return head;
            }

            if (ret != NULL)
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
            if (count % k == 0)
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
    s.print(s.reverseGroup(head.next, 2));
    return 0;
}
