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
    static bool nodeCmp(ListNode *a, ListNode *b)
    {
        if (a->val > b->val)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode *> data;

        ListNode *node = NULL;
        for (int i = 0; i < lists.size(); ++i)
        {
            node = lists[i];
            while (node != NULL)
            {
                data.push_back(node);
                node = node->next;
            }
        }

        make_heap(data.begin(), data.end(), nodeCmp);

        ListNode head(0);
        ListNode *tail = &head;
        while (!data.empty())
        {
            pop_heap(data.begin(), data.end(), nodeCmp);
            node = data.back();

            tail->next = node;
            tail = tail->next;

            data.pop_back();
        }
        tail->next = NULL;

        return head.next;
    }

    int smallest(vector<ListNode*> &lists)
    {
        int small = 1 << 30;
        int index = -1;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] != NULL)
            {
                if (lists[i]->val < small)
                {
                    index = i;
                }
            }
        }

        return index;
    }

    int fillFinish(bool *finish, vector<ListNode*> &lists)
    {
        int count = 0;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] == NULL)
            {
                finish[i] = true;
            }
            else
            {
                ++count;
                finish[i] = false;
            }
        }

        return count;
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
    vector<ListNode*> lists;
    ListNode*a = new ListNode(0);
    a->next = new ListNode(2);
    a->next->next = new ListNode(5);
//    a->next->next->next = new ListNode(-1);
    lists.push_back(a);

    ListNode *b = new ListNode(1);
    b->next = new ListNode(1);
    b->next->next = new ListNode(2);

//    lists.push_back(NULL);
    s.print(s.mergeKLists(lists));
    return 0;
}
