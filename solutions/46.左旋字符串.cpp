class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n == 0) return str;
        
        string new_str = "";
        new_str.resize(str.size());
        for(int i = 0; i<str.size(); ++i){
            int new_index = (i-n < 0) ? (i - n + str.size()) : i - n;
            new_str[new_index] = str[i];
        }
        return new_str;
    }
};