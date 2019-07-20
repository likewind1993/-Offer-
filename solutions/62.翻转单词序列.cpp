#include <iostream>
#include <string>
using namespace std;

class Solution {
    int findSpace(string & str, int p)
    {
        while (p >= 0 && str[p] != ' ')
            --p;
        return p;
    }
public:
    string ReverseSentence(string str)
    {
        string ans = "";
        int p = str.size() - 1;
        if (p == 0)
            return str;
        while (p >= 0)
        {
            int begin = findSpace(str, p);
            for (int i = begin + 1; i <= p; ++i)
            {
                ans += str[i];
            }
            if (begin > 0 || (begin == 0 && str[begin] == ' ')) ans += ' ';
            p = begin - 1;
        }
        return ans;
    }
};
int main() {
    Solution solution;
    cout<<solution.ReverseSentence("student. a am I")<<"123";

    return 0;
}