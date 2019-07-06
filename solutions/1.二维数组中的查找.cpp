class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int n = array.size(), m = array[0].size();
        int i = n - 1, j = 0;
        while(i >= 0 && j<m){
            if(array[i][j] == target) return true;
            else if(array[i][j] > target) --i;
            else if(array[i][j] < target) ++j;
        }
        return false;
    }
};