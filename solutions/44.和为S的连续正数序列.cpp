class Solution {
    int calcSum(int i, int j){
        int n = (j - i + 1), res = 0;
        if((n & 1) == 0){
            res = (i + j) * ( n / 2);
        }else{
            res = (i + j) * (n / 2) + (i+j)/2;
        }
        return res;
    }
    void pushSeq(vector<vector<int>> & ans, int i , int j){
        vector<int> nums;
        while(i<=j){
            nums.push_back(i++);
        }
        ans.push_back(nums);
    }
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ans;
        if(sum <= 2) return ans;
        
        int l = 1, r = 2;
        while(r <= sum / 2 + 1){
            int cur_sum = calcSum(l, r);
            if(cur_sum == sum){
                pushSeq(ans, l, r);
                ++r;
            }else if(cur_sum < sum){
                ++r;
            }else {
                ++l;
            }
        }
        return ans;
    }
};