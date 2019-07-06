class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        ListNode * p_pre_head = new ListNode(-1);
        p_pre_head->next = pHead;
        ListNode * p_pre = p_pre_head, * p_cur = pHead;
        while(p_cur !=NULL && p_cur->next != NULL){
            ListNode * p_next = p_cur->next;
            bool is_sp = true;
            while(p_next != NULL && p_cur->val == p_next->val){
                p_next = p_next->next;
                is_sp = false;
            }
            if(!is_sp){
                p_pre->next = p_next;
            } else {
                p_pre = p_cur;
            }
            p_cur = p_next;
        }
        return p_pre_head->next;
    }
};