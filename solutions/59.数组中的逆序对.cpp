#include <iostream>
#include <vector>
using namespace std;

class Solution {
    
private:
    int MOD = 1000000007;
    long long int InversePairsCore(vector<int> & data, vector<int> & data_copy, int l, int r)
    {
        if (l == r)
        {
            data_copy[l] = data[l];
            return 0;
        }
        int length = (r - l) / 2;
        long long int left = InversePairsCore(data_copy, data, l, l + length) % MOD;
        long long int right = InversePairsCore(data_copy, data,  l + length + 1, r) % MOD;
        long long int ans = 0;
        int i = l + length, j = r, p = r;
        
        while (i >= l && j >= l + length + 1)
        {
            if (data[i] > data[j])
            {
                data_copy[p--] = data[i--];
                ans += j - l - length;
            }
            else
            {
                data_copy[p--] = data[j--];
            }
        }
        while (i >= l)
            data_copy[p--] = data[i--];
        while (j >= l + length + 1)
            data_copy[p--] = data[j--];
        ans = ans % MOD;
        return (left + right + ans) % MOD;
    }


public:
    int InversePairs(vector<int> data)
    {
        int n = data.size();
        if (n <= 1) return 0;
        vector<int> data_copy(data.begin(), data.end());
        int ans = InversePairsCore(data, data_copy, 0, n - 1);

        return ans;
    }
};
int main() {
    vector<int> data = {1,2,3,4,5,6,7,0};
    Solution solution;
    cout<<solution.InversePairs(data)<<endl;

    return 0;
}