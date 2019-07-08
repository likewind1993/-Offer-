class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() <=1 ) return ;
        int res = 0;
        for(auto & num : data)
            res ^= num;
        int bit_1 = 1;
        while((res & 1 ) == 0){
            res = res>>1;
            bit_1 = bit_1<<1;
        }
        *num1 = 0, * num2 = 0;
        for(auto & num : data){
            if((num & bit_1) == 0)
                (*num1) = (*num1) ^ num;
            else 
                (*num2) = (*num2) ^ num;
        }
    }
};