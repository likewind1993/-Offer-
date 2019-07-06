class Solution {
public:
    void printListRe(ListNode* head, vector<int>& ans){
        if(head != NULL){
            printListRe(head->next, ans);
            ans.push_back(head->val);
        }
    }
    
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        printListRe(head, ans);
        return ans;
    }
};