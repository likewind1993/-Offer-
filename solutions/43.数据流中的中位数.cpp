//Solution 1. base vector

// class Solution {
// private:
//     vector<int> nums_;

//     void swap(int i, int j)
//     {
//         int temp = nums_[i];
//         nums_[i] = nums_[j];
//         nums_[j] = temp;
//     }

// public:
//     void Insert(int num)
//     {
//         nums_.push_back(num);
//         int  j = nums_.size() - 1;

//         for (int i = j - 1; i >= 0; --i)
//         {
//             if (nums_[i] > nums_[j])
//             {
//                 swap(i, j);
//                 --j;
//             }
//             else if (nums_[i] < nums_[j])
//                 break;
//         }

//     }

//     double GetMedian()
//     {
//         if (nums_.empty()) return -1;
//         int n = nums_.size();
//         if(n % 2 == 1)
//             return nums_[n / 2];


//         double res = (nums_[n / 2] + nums_[(n / 2) - 1]) / 2.0;

//         return res;
//     }

// };

//Solution 2. base min, max, heap 
class Solution {
private:
    vector<int> min_;
    vector<int> max_;

    int pop_min_heap()
    {
        pop_heap(min_.begin(), min_.end(), greater<int>());
        int res = min_[min_.size() - 1];
        min_.pop_back();
        return res;
    }
    int pop_max_heap()
    {
        pop_heap(max_.begin(), max_.end());
        int res = max_[max_.size() - 1];
        max_.pop_back();
        return res;
    }

public:
    void Insert(int num)
    {
        if (((min_.size() + max_.size()) & 1) == 0)
        {
            if (min_.size() > 0 && min_[0] <= num)
            {
                min_.push_back(num);
                push_heap(min_.begin(), min_.end(), greater<int>());
                num = pop_min_heap();
            }
            max_.push_back(num);
            push_heap(max_.begin(), max_.end());
        }
        else
        {
            if (max_[0] >= num)
            {
                max_.push_back(num);
                push_heap(max_.begin(), max_.end());
                num = pop_max_heap();
            }
            min_.push_back(num);
            push_heap(min_.begin(), min_.end(), greater<int>());
        }
    }
    double GetMedian()
    {
        int n = max_.size() + min_.size();
        if (n == 0) return -1;
        if ((n & 1) == 1)
            return max_[0];
        return (max_[0] + min_[0]) / 2.0;
    }

};