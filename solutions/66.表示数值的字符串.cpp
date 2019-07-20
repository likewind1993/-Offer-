class Solution {
public:
    bool isNumeric(char* string)
    {
        int i = 0;
        while(string[i] != '\0'){
            if((i != 0) && (string[i] == '+' || string[i] == '-'))
                return false;
            if(string[i]>='0' && string[i]<='9') continue;
            
            return false;
        }
        return true;
    }

};