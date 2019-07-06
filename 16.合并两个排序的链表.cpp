class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode * p_dummy = new ListNode(-1);
        ListNode * p_cur = p_dummy;
        while(pHead1 != NULL && pHead2 != NULL){
            if(pHead1->val<=pHead2->val){
                p_cur->next = pHead1;
                pHead1 = pHead1->next;
            }else {
                p_cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            p_cur = p_cur->next;
        }
        if(pHead1 == NULL) p_cur->next = pHead2;
        if(pHead2 == NULL) p_cur->next = pHead1;
        
        return p_dummy->next;
    }
};