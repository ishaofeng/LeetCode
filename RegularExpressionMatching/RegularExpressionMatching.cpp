class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*s == '\0')
        {
            while (*p && *(p+1) == '*')
            {
                p += 2;
            }
        }
        if (*s == '\0' && *p == '\0')
        {
            return true;
        }
        else if (*s == '\0' && *p != '\0' || *s != '\0' && *p == '\0')
        {
            return false;
        }
        
        bool result = true;
        if (*(p+1) == '*')
        {
            result = ((*s == *p || *p == '.') && isMatch(s + 1, p)) || isMatch(s, p + 2);
        }
        else
        {
            result = (*s == *p || *p == '.') && isMatch(s + 1, p + 1);
        }
        
        return result;
    }
};
