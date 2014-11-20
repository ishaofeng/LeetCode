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
using namespace std;

class MinStack
{
private:
    stack<int> s;
    stack<int> m;
public:
    void push(int x)
    {
        s.push(x);
        if (s.empty() || m.top() >= x)
        {
            m.push(x);
        }
    }

    void pop()
    {
        if (!s.empty())
        {
            if (!m.empty() && s.top() == m.top())
            {
                m.pop();
            }
            s.pop();
        }
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return m.top();
    }
};

int main()
{
    MinStack s;
    s.push(-3);
}
