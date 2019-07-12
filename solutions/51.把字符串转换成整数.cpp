class Solution {
public:
    int StrToInt(string str)
    {
        if (str.empty()) return 0;
        long long int ans = 0;
        bool is_positive = true, is_legal = true;
        int l = 0, r = str.size() - 1, bits = 0;
        if (str[l] == '-')
        {
            is_positive = false;
            ++l;
        }
        else if (str[l] == '+')
            ++l;
        while (r >= l)
        {
            if (str[r] > '9' || str[r] < '0')
            {
                is_legal = false;
                break;
            }
            ans += (str[r--] - '0') * pow(10, bits++) ;
            if ((is_positive && ans > INT_MAX) || (!is_positive && ans < INT_MIN))
            {
                is_legal = false;
                break;
            }
        }
        if (!is_positive)
            ans = (-1) * ans;
        return is_legal ? ans : 0;
    }
};