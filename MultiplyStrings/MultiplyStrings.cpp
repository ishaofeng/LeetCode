class Solution {
public:
    string multiply(string num1, string num2) {
        string result;
        
        if (num1.length() < num2.length())
        {
            num1.swap(num2);
        }
        
        if (num2.length() == 1 && num2[0] == '0')
        {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int r, a, k = -1, j = 0;
        for (int i = 0; i < num2.length(); ++i)
        {
            a = 0;
            j = 0;
            for (; j < num1.length(); ++j)
            {
                r = (num1[j] - '0') * (num2[i] - '0') + a;
                if ((j+i) > k)
                {
                    result.push_back('0');
                    ++k;
                }
                r += result[j + i] - '0';
                
                result[i + j] = (r % 10) + '0';
                a = r / 10;
            }
            
            while (a != 0)
            {
                if ((j+i) > k)
                {
                    result.push_back('0');
                    ++k;
                }
                r = result[j + i] - '0' + a;
                result[j + i] = (r % 10) + '0';
                a = r / 10;
                ++j;
            }
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
