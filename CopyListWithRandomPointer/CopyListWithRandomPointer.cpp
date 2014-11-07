#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }

        RandomListNode *node = head, *insert;
        while (node != NULL)
        {
            insert = new RandomListNode(node->label);
            insert->next = node->next;

            node->next = insert;

            node = node->next->next;
        }

        node = head;


        while (node != NULL)
        {
            if (node->random)
            {
                node->next->random = node->random->next;
            }

            node = node->next->next;
        }

        RandomListNode newhead(0);
        RandomListNode *tail= &newhead, *prev = NULL;
        node = head;
        while (node != NULL)
        {
            tail->next = node->next;
            tail = tail->next;

            node->next = node->next->next;
            prev = node;
            node = node->next;
        }
        if (prev != NULL)
        {
            prev->next = NULL;
        }
        else
        {
            head->next = NULL;
        }

        tail->next = NULL;


        return newhead.next;
    }

    void print(RandomListNode*head)
    {
        if  (head != NULL)
        {
            cout << head->label << " ";
            if (head->random)
            {
                cout << head->random->label;
            }
            else
            {
                cout << "NONE";
            }
            cout << "# ";
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
    RandomListNode head(0), *newnode;
    for (int i = 0; i < len; ++i)
    {
        newnode = new RandomListNode(val[i]);
        newnode->next = head.next;

        head.next = newnode;
    }

    Solution s;
    vector<RandomListNode*> lists;
    RandomListNode*a = new RandomListNode(6);
    a->next = new RandomListNode(2);
    a->next->next = new RandomListNode(5);
    a->next->random = a;
    a->next->next->next = new RandomListNode(-1);
    a->next->next->next->random = a;
//    a->next->next->next->next = a->next->next;
    lists.push_back(a);

    RandomListNode *b = new RandomListNode(1);

    s.print(a);
    b = s.copyRandomList(a);
    s.print(b);
    return 0;
}
