class Solution {
    int Min(int n1, int n2, int n3){
        int n1n2 = min(n1, n2);
        return min(n1n2, n3);
    }
    
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0) return 0;
        
        vector<int> ugly_numbers(index, 0);
        ugly_numbers[0] = 1;
        int i_multi_2 = 0, i_multi_3 = 0, i_multi_5 = 0, next = 1;
        
        while(next < index){
            int min_ = Min(ugly_numbers[i_multi_2] * 2, ugly_numbers[i_multi_3] * 3, ugly_numbers[i_multi_5] * 5);
            ugly_numbers[next] = min_;
            while(ugly_numbers[i_multi_2] * 2<= min_)
                ++i_multi_2;
            while(ugly_numbers[i_multi_3] * 3<= min_)
                ++i_multi_3;
            while(ugly_numbers[i_multi_5] * 5<= min_)
                ++i_multi_5;
            ++next;
        }
        return ugly_numbers[index-1];
    }
};