class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k == 0) return NULL;
        ListNode * p_dummy = new ListNode(-1);
        p_dummy->next = pListHead;
        ListNode * p_slow = p_dummy, * p_fast = pListHead;
        
        for(unsigned int i = 0; i<k-1; ++i){
            p_fast = p_fast->next;
            if(p_fast == NULL) return NULL;
        }
        while(p_fast != NULL){
            p_fast = p_fast->next;
            p_slow = p_slow->next;
        }
        return p_slow;
    }
};