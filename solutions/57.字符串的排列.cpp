#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    void findPermutaion(vector<string> & ans, vector<bool> & is_visited, string & str, string s, int p){
        if(p == str.size()){
            ans.push_back(s);
            return ;
        }
        for(int i = 0; i<str.size(); ++i){
            if(i !=0 && str[i-1] == str[i] && !is_visited[i-1])
                continue;
            if(!is_visited[i]){
                is_visited[i] = true;
                findPermutaion(ans, is_visited, str, s + str[i], p+1);
                is_visited[i] = false;
            }
        }
    }
    
public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        vector<bool> is_visited(str.size(), false);
        if(str.empty()) return ans;
        sort(str.begin(), str.end());
        findPermutaion(ans, is_visited, str, "", 0);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> ans = solution.Permutation("aaabc");
    for(auto a : ans){
        cout<<a<<endl;
    }
    return 0;
}