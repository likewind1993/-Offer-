#include <iostream>
using namespace std;
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ans = 0;
        for(int i = 1; i<=n; i*=10){
            int a = n / i;
            int b = n % i;
            ans += a % 10 == 1 ? a / 10 * i + (b+1) : (a+8) / 10 * i;
        }
        return ans;
    }
};
int main() {
    Solution solution;
    cout<<solution.NumberOf1Between1AndN_Solution(13)<<endl;

    return 0;
}