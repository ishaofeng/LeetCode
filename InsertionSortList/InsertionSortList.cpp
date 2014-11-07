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
    ListNode *insertionSort(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *node = head->next, *insert, *prev = head, *insertPrev, *next;
        int val;
        while (node != NULL)
        {
            val = node->val;
            insert = head;
            insertPrev = NULL;
            while (insert->val < val && insert != node)
            {
                insertPrev = insert;
                insert = insert->next;
            }

            //首节点
            if (insertPrev == NULL)
            {
                next = node->next;

                prev->next = node->next;

                node->next = head;
                head = node;

                node = next;
            }
            else
            {
                if (insert != node)
                {
                    next = node->next;
                    prev->next = node->next;

                    node->next = insert;
                    insertPrev->next = node;

                    node = next;
                }
                else
                {
                    prev = node;
                    node = node->next;
                }
            }
        }

        return head;
    }

    void print(ListNode *head)
    {
        if  (head != NULL)
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
    ListNode*a = new ListNode(6);
    a->next = new ListNode(2);
    a->next->next = new ListNode(5);
    a->next->next->next = new ListNode(-1);
//    a->next->next->next->next = a->next->next;
    lists.push_back(a);

    ListNode *b = new ListNode(1);
    b->next = new ListNode(1);
    b->next->next = new ListNode(2);

//    lists.push_back(NULL);
    b = s.insertionSort(a);
    s.print(b);
    return 0;
}
