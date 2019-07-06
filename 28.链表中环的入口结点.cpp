class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        ListNode * p_fast = pHead, * p_slow = pHead;
        while(p_fast != NULL && p_fast->next != NULL){
            p_fast = p_fast->next->next;
            p_slow = p_slow->next;
            if(p_slow == p_fast){
                ListNode * temp = pHead;
                while(temp != p_slow){
                    temp = temp->next;
                    p_slow = p_slow->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};