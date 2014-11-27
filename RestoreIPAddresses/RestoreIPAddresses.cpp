class Solution {
public:
    bool check(string &s, int start, int len)
    {
        if (len > 3 || len <= 0)
        {
            return false;
        }
        if (s[start] == '0' && len >= 2)
        {
            return false;
        }
        if (len <= 2)
        {
            return true;
        }

        if (s[start] < '2' || s[start] == '2' && (s[start+1] < '5' || s[start+1] == '5' && s[start+2] <= '5'))
        {
            return true;
        }

        return false;
    }

    void restoreIpAddressesHelp(string &s, int start, string &item, int depth, vector<string> &result)
    {
        int il = item.length();
        if (depth == 4)
        {
            int len = s.length() - start;
            if (check(s, start, len))
            {
                item.append(s, start, len);

                result.push_back(item);
                item.erase(il, len);
            }

            return ;
        }

        if (start >= s.length())
        {
            return ;
        }

        for (int i = 0; i < 3 && (start + i + 1) < s.length(); ++i)
        {
            if (check(s, start, i + 1))
            {
                item.append(s, start, i + 1);
                item.append(".");

                restoreIpAddressesHelp(s, start + i + 1, item, depth + 1, result);

                item.erase(il, i + 2);
            }
        }

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string item;
        restoreIpAddressesHelp(s, 0, item, 1, result);

        return result;
    }
};
