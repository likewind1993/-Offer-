#include <iostream>
using namespace std;
class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum, carry;
        do {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        } while (num2 != 0);
        return num1;
    }
};
int main(){
    Solution solution;
    cout<<solution.Add(11, 19)<<endl;

    return 0;
}