class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ans;
        if(array.size() < 2) return ans;
        
        int i = 0, j = array.size() - 1, biggest = array[array.size()-1];
        int res1 = biggest, res2 = biggest;
        while(i<j){
            if(array[i] + array[j] == sum) {
                if((res1 == biggest && res2 == biggest) || res1 * res2 > array[i]*array[j]) {
                    res1 = array[i];
                    res2 = array[j];
                }
            }
            if(array[i] + array[j] < sum)
                ++i;
            else 
                --j;
        }
        if(res1 == biggest && res2 == biggest)
            return ans;
        ans.push_back(res1);
        ans.push_back(res2);
        return ans;
    }
};