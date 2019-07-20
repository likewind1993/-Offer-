#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        if(n == 0) return vector<int>{};
        if(n == 1) return vector<int> {1};
        vector<int> ans(n, 0), left(n, 1), right(n, 1);
        int multi = 1;
        for(int i = 1; i<n; ++i){
            multi = multi*A[i-1];
            left[i] = multi;
        }
        multi = 1;
        for(int i = n-2; i>=0; --i){
            multi = multi*A[i+1];
            right[i] = multi;
        }
        for(int i = 0; i<n; ++i){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> data = {2, 3, 4, 5};
    vector<int>ans = solution.multiply(data);
    for(auto a : ans)
        cout<<a<<endl;
    return 0;
}