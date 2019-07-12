class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()) return -1;
        vector<int> chars(256, 0);
        for(int i = 0; i<str.size(); ++i){
            chars[str[i]]++;
        }
        for(int i = 0; i<str.size(); ++i){
            if(chars[str[i]] == 1)
                return i;
        }
        return -1;
    }
};