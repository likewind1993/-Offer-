class Solution {
    void findMinRe(vector<int>& rotateArray, int & ans, int begin, int end)
    {
        if (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (mid > 0 && rotateArray[mid - 1] > rotateArray[mid])
            {
                ans = rotateArray[mid];
                return;
            }
            if (rotateArray[mid] > rotateArray[end])
                findMinRe(rotateArray, ans, mid + 1, end);
            else if(rotateArray[mid] < rotateArray[end])
                findMinRe(rotateArray, ans, begin, mid - 1);
            else {
                findMinRe(rotateArray, ans, mid + 1, end);
                findMinRe(rotateArray, ans, begin, mid - 1);
            }
        }
    }
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.empty())
            return 0;
        int ans = rotateArray[0];
        findMinRe(rotateArray, ans, 0, rotateArray.size() -1);
        return ans;
    }
};