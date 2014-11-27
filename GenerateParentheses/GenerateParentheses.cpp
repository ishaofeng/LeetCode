#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void generateHelp(int ln, int rn, string &s, vector<string> &result)
    {
        if (ln == 0 && rn == 0)
        {
            result.push_back(s);
            return ;
        }
        
        if (ln == rn)
        {
            s.push_back('(');
            generateHelp(ln - 1, rn, s, result);
            s.pop_back();
        }
        else
        {
            if (ln > 0)
            {
                s.push_back('(');
                generateHelp(ln - 1, rn, s, result);
                s.pop_back();
            }
            
            s.push_back(')');
            generateHelp(ln, rn - 1, s, result);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string> result;
       string s;
       
       generateHelp(n, n, s, result);
       
       return result;
    }
};
