class Solution {
    multiset<int, greater<>> set_;
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        int n = input.size();
        vector<int> ans;
        if(n<k) return ans;
        
        for(int i = 0; i<n; ++i) {
            if(set_.size() < k) {
                set_.insert(input[i]);
            }else {
                if(input[i] < (*set_.begin())) {
                    set_.erase(set_.begin());
                    set_.insert(input[i]);
                }
            }
        }
        for(auto iter : set_) {
            ans.push_back(iter);
        }
        return ans;
    }
};