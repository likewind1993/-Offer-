//Solution 1: Partition.
class Solution {
    void swap(vector<int> & number, int i, int j)
    {
        int temp = number[i];
        number[i] = number[j];
        number[j] = temp;
    }
    int partition(vector<int> & numbers, int begin, int end)
    {
        int x = numbers[end], i = begin - 1;
        for (int j = begin; j < end; ++j)
        {
            if (numbers[j] < x)
            {
                ++i;
                swap(numbers, i, j);
            }
        }
        swap(numbers, i + 1, end);
        return i + 1;
    }
    bool check(vector<int> & numbers, int num){
        int n = numbers.size(), count = 0;
        for(int i = 0; i<n; ++i){
            if(numbers[i] == num)
                ++count;
        }
        if(count > (n / 2))
            return true;
        return false;
    }
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.empty()) return 0;
        int n = numbers.size();
        int l = 0, r = n - 1;
        int p = partition(numbers, l, r);
        while (p != (n / 2))
        {
            if (p < (n / 2)) {
                l = p+1;
                p = partition(numbers, l, r);
            }  
            else {
                r = p-1;
                p = partition(numbers, l, r);
            }
        }
        return check(numbers, numbers[p]) ? numbers[p] : 0;
    }
};

