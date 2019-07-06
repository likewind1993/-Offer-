class Solution {
    unordered_map<int, RandomListNode*> m_original;
    unordered_map<int, RandomListNode*> m_new;
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        RandomListNode * p_dummy = new RandomListNode(-1);
        RandomListNode * p_pre = p_dummy, * p_original = pHead, * p_new = NULL;
        while(p_original != NULL){
            p_new = new RandomListNode(p_original->label);
            
            m_original[p_original->label] = p_original->random;
            m_new[p_original->label] = p_new;
            
            p_pre->next = p_new;
            p_pre = p_new;
            p_original = p_original->next;
        }
        p_new = p_dummy->next;
        while(p_new != NULL){
            int label = p_new->label;
            if(m_original[label] == NULL)
                p_new->random = NULL;
            else {
                int target_label = m_original[label]->label;
                p_new->random = m_new[target_label];
            }
            p_new = p_new->next;
        }
        return p_dummy->next;
    }
};