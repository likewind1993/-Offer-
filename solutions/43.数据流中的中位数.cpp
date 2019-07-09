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