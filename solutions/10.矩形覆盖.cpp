class Solution {
public:
    int rectCover(int number) {
        if(number<=2) return number;
        int sub_2 = 1, sub_1 = 2, ans = 0;
        for(int i = 3; i<=number; ++i){
            ans = sub_1 + sub_2;
            sub_2 = sub_1;
            sub_1  = ans;
        }
        return ans;
    }
};