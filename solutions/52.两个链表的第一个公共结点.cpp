class Solution {
    int calcListLength(ListNode * pHead){
        int length = 0;
        while(pHead != 0){
            pHead = pHead->next;
            ++length;
        }
        return length;
    }
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode * p1 = pHead1, * p2 = pHead2;
        int length1 = calcListLength(pHead1), length2 = calcListLength(pHead2);
        if(length1 > length2){
            int diff = length1 - length2;
            while(diff-- > 0)
                p1 = p1->next;
        }else if(length1 < length2){
            int diff = length2 - length1;
            while(diff-- > 0)
                p2 = p2->next;
        }
        while(p1 != NULL && p2 != NULL && p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};