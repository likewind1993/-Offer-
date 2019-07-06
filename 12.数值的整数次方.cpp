class Solution {
public:
    double PowerRe(double base, int exponent){
        if(exponent == 1)
            return base;
        int res = pow(PowerRe(base, exponent>>1), 2);
        return (exponent & 1 == 1) ? res * base : res;
    }
    
    double Power(double base, int exponent) {
        if(exponent == 0)
            return 1;
        if(base == 0) 
            return 0;
        double ans = PowerRe(base, abs(exponent));
        return exponent < 0 ? 1/ans : ans;
    }
};