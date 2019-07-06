class Solution {
public:
	void replaceSpace(char *str,int length) {
        int final_length = 0;
        for(int i = 0; i<length; ++i){
            if(str[i] == ' ')
                final_length+=3;
            else 
                final_length+=1;
        }
        str[final_length--] = '\0';
        for(int i = length - 1; i>=0; --i){
            if(str[i] == ' '){
                str[final_length--] = '0';
                str[final_length--] = '2';
                str[final_length--] = '%';
            }else {
                str[final_length--] = str[i];
            }
        }
	}
};