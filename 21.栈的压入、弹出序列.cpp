class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.empty() && popV.empty()) return true;
        if (pushV.size() != popV.size()) return false;
        stack<int> s;
        int i = 0, j = 0;
        while (j < popV.size())
        {
            while (s.empty() || s.top() != popV[j])
            {
                if (i == pushV.size())
                    break;
                s.push(pushV[i++]);
            }
            if (s.top() != popV[j])
                break;
            s.pop();
            ++j;
        }
        return s.empty();
    }
};