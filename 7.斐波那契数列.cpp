class Solution {
public:
    int Fibonacci(int n)
    {
        int res[2] = { 0, 1 };
        if (n <= 1) return res[n];
        int  f_sub_2 = res[0], f_sub_1 = res[1], ans = 0;
        for (int i = 2; i <= n; ++i)
        {
            ans = f_sub_1 + f_sub_2;
            f_sub_2 = f_sub_1;
            f_sub_1 = ans;
        }
        return ans;
    }
};
