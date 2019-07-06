class Solution {
private:
    stack<int> s;
    stack<int> s_min;
    
public:
    void push(int value) {
        if(s_min.empty()) s_min.push(value);
        else if(value > s_min.top()) s_min.push(s_min.top());
        else if(value <= s_min.top()) s_min.push(value);
        s.push(value);
    }
    void pop() {
        s.pop();
        s_min.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return s_min.top();
    }
};