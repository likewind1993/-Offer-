class Solution {
    void findFirstK(vector<int> & data, int k, int begin, int end, int & pos)
    {
        if (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (data[mid] == k && mid < pos)
            {
                pos = mid;
                findFirstK(data, k, begin, mid-1, pos);
            }
            else if (data[mid] < k)
            {
                findFirstK(data, k, mid + 1, end, pos);
            }
        }
    }
    void findLastK(vector<int> & data, int k, int begin, int end, int & pos)
    {
        if (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (data[mid] == k && mid > pos)
            {
                pos = mid;
                findLastK(data, k, mid+1, end, pos);
            }
            else if (data[mid] > k)
            {
                findLastK(data, k, begin, mid-1, pos);
            }
        }
    }
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        if (data.empty()) return 0;
        int begin = 0, end = data.size() - 1;
        int first_pos = end+1, last_pos = -1;
       
        findFirstK(data, k, begin, end, first_pos);
        findLastK(data, k, begin, end, last_pos);
        //return first_pos;
        if(first_pos == end + 1 && last_pos == -1)
            return 0;
        return (last_pos - first_pos + 1);
    }
};