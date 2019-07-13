class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ans;
        if(size>num.size() || size <= 0) return ans;
        
        int l = 0, r = size - 1;
        while(r < num.size()){
            int max_val = num[l];
            for(int i = l; i<=r; ++i){
                max_val = max(max_val, num[i]);
            }
            ans.push_back(max_val);
            ++l;
            ++r;
        }
        return ans;
    }
};