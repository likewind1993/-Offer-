class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        int ans = INT_MIN, last = INT_MIN;
        for(int i = 0; i<array.size(); ++i){
            if(last > 0 )
               last = last + array[i];
            else 
               last = array[i];
            ans = max(ans, last);
        }
        return ans;
    }
};