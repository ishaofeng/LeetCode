#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length())
        {
            a.swap(b);
        }
        
        int k = 0;
        string result;
        auto as = a.rbegin();
        auto bs = b.rbegin();
        
        while (bs < b.rend())
        {
            k += *as - '0' + *bs - '0';
            result.append(1, char(k % 2 + '0'));
            k /= 2;
            
            ++bs;
            ++as;
        }
        while (as < a.rend())
        {
            k += *as - '0';
            result.append(1, char(k % 2 + '0'));
            k /= 2;
            
            ++as;
        }
        
        if (k > 0)
        {
            result.append("1");
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
