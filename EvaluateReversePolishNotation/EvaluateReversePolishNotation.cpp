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

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        int result;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                switch(tokens[i][0])
                {
                    case '+':
                        result = a + b;
                        break;
                    case '-':
                        result = a - b;
                        break;
                    case '*':
                        result = a * b;
                        break;
                    case '/':
                        result = a / b;
                        break;
                    default:
                        break;
                }
                s.push(result);
            }
            else
            {
                s.push(atoi(tokens[i].data()));
            }
        }

        return s.top();
    }
};

int main()
{
    Solution s;
    vector<string> ss;
    ss.push_back("2");
    ss.push_back("1");
    ss.push_back("+");
    ss.push_back("3");
    ss.push_back("*");
    cout << s.evalRPN(ss) << endl;

    vector<vector<int> > result;
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[0].size(); ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
