#include <iostream>
#include <vector>
#include <set>
#include <cctype>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <limits>
#include <algorithm>
#include <list>
#include <utility>
#include <cstdlib>
using namespace std;


class LRUCache
{
    struct Node
    {
        int key;
        int val;
        Node *prev;
        Node *next;
        Node() : val(0), prev(NULL), next(NULL) {}
        Node(int key, int val) : key(key), val(val), prev(NULL), next(NULL) {}
    };
private:
    Node head;
    int capacity;
    int size;
    unordered_map<int, Node *> m;

    void detach(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = NULL;
        node->prev = NULL;
    }

    void append(Node *node)
    {
        node->next = head.next;
        node->prev = &head;

        head.next->prev = node;
        head.next = node;
    }
public:
    LRUCache(int c)
    {
        capacity = c;
        size = 0;

        head.next = &head;
        head.prev = &head;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }

        Node *node = m[key];
        detach(node);
        append(node);

        return node->val;
    }

    void set(int key, int value)
    {
        Node *node = NULL;
        if (m.find(key) == m.end())
        {
            if (size == capacity)
            {
                node = head.prev;
                m.erase(node->key);
                detach(node);
                delete node;
            }
            else
            {
                ++size;
            }
            node = new Node(key, value);
            append(node);

            m[key] = node;
        }
        else
        {
            node = m[key];
            node->val = value;

            detach(node);
            append(node);
        }
    }

    void printCache()
    {
        Node *k = head.next;
        while (k != &head)
        {
            cout << k->key << " " << k->val << endl;
            k = k->next;
        }

        for (unordered_map<int, Node*>::iterator it = m.begin(); it != m.end(); ++it)
        {
            cout << it->first << " ";
        }
        cout << endl;
    }
};

int main()
{
    LRUCache cache(10);
    cache.set(1, 2);
    cache.set(2, 20);
    cache.set(1, 3);
    for (int i = 0; i < 30; ++i)
    {
        cache.set(i + 10, i + 30);
    }
    cout << cache.get(1) << endl;
    cache.printCache();
}
