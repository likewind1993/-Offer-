class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        
        ListNode * p_dummy = new ListNode(-1);
        p_dummy->next = pHead;
        
        ListNode * p_cur = pHead;
        while(p_cur != NULL && p_cur->next != NULL){
            ListNode * p_next = p_cur->next;
            p_cur->next = p_next->next;
            p_next->next = p_dummy->next;
            p_dummy->next = p_next;
        }
        
        return p_dummy->next;
    }
};