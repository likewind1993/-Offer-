class Solution
{
private:
    int table[256];
    int index;
public:
    Solution()
    {
        index  = 0;
        for (int i = 0; i < 256; ++i)
            table[i] = -1;
    }
    //Insert one char from stringstream
    void Insert(char ch)
    {
        if(table[ch] == -1){
            table[ch] = index;
        }else if(table[ch] >= 0)
            table[ch] = -2;
        ++index;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int min_index = INT_MAX;
        int ch = '#';
        for(int i = 0; i<256; ++i){
            if(table[i] >= 0 && table[i] < min_index){
                ch = (char)i;
                min_index = table[i];
            }
        }
        return ch;
    }
};