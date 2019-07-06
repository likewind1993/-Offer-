class Solution {
    bool isMatch(char * str, char * pattern, int i_s, int i_p)
    {
        if (str[i_s] == '\0' && pattern[i_p] == '\0') return true;
        if (str[i_s] != '\0' && pattern[i_p] == '\0') return false;
        bool first_match = (str[i_s] != '\0') && (str[i_s] == pattern[i_p] || pattern[i_p] == '.');
        if (pattern[i_p + 1] == '*')
        {
            return (first_match && isMatch(str, pattern, i_s + 1, i_p)) ||
                isMatch(str, pattern, i_s, i_p + 2);
        }
        return first_match && isMatch(str, pattern, i_s + 1, i_p + 1);
    }
public:
    bool match(char* str, char* pattern)
    {
        if (str == pattern) return true;
        if (str == NULL || pattern == NULL) return false;
        return isMatch(str, pattern, 0, 0);
    }
};