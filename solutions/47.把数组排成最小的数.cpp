bool cmp(int & a, int & b){
    int a_copy = a, b_copy = b, a_bits = 0, b_bits = 0;
    if(a_copy == 0) a_bits = 1;
    if(b_copy == 0) b_bits = 1;
    while(a_copy){
        a_copy = a_copy / 10;
        ++a_bits;
    }
    while(b_copy){
        b_copy = b_copy / 10;
        ++b_bits;
    }
    int ab = a * pow(10, b_bits) + b;
    int ba = b * pow(10, a_bits) + a;
    return ab < ba;
}

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        string str = "";
        for(int i = 0; i<numbers.size(); ++i){
            str += to_string(numbers[i]);
        }
        int i = 0;
        while(str[i] == '0') ++i;
        return str.substr(i, str.size());
    }
};