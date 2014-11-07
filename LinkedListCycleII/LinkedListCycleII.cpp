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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        ListNode *slow = head, *fast = head;
        while (fast->next != NULL)
        {
            fast = fast->next;
            if (fast->next != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }

            if (fast == slow)
            {
                break;
            }
        }

        if (fast == slow)
        {
            while (head != slow)
            {
                head = head->next;
                slow = slow->next;
            }

            return head;
        }

        return NULL;
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
    vector<ListNode*> lists;
    ListNode*a = new ListNode(0);
    a->next = new ListNode(2);
    a->next->next = new ListNode(5);
    a->next->next->next = new ListNode(-1);
    a->next->next->next->next = a->next->next;
    lists.push_back(a);

    ListNode *b = new ListNode(1);
    b->next = new ListNode(1);
    b->next->next = new ListNode(2);

//    lists.push_back(NULL);
    b = s.detectCycle(a);
    if (b != NULL)
    {
        cout << b->val << endl;
    }
    return 0;
}
