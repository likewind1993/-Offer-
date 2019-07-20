#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int n = numbers.size();
        if(n <= 1) return false;
        sort(numbers.begin(), numbers.end());
        int i = 0, jokers = 0;
        while(numbers[i] == 0) {
            ++jokers;
            ++i;
        }
        for(; i<n-1; ++i){
            while(numbers[i] + 1 < numbers[i+1] && jokers > 0){
                numbers[i]++;
                jokers--;
            }
            if(numbers[i] + 1 != numbers[i+1])
                return false;
        }
        return true;
    }
};
int main() {
    vector<int> data = {0,3,1,6,4};
    Solution solution;
    cout<<solution.IsContinuous(data)<<endl;

    return 0;
}