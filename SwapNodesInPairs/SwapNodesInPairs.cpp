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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *next = head->next;
        head->next = swapPairs(head->next->next);
        next->next = head;

        return next;
    }

    void print(ListNode *head)
    {
        if (head != NULL)
        {
            cout << head->val << " ";
            print(head->next);
        }
    }
};


int main()
{
    int val[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(val) / sizeof(val[]);
    ListNode head(0), *newnode;
    for (int i = 0; i < len; ++i)
    {
        newnode = new ListNode(val[i]);
        newnode->next = head.next;

        head.next = newnode;
    }
    Solution s;
    s.print(s.swapPairs(head.next));
    return 0;
}
