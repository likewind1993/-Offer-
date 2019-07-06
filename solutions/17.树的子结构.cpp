class Solution {
public:
    
    bool isEqual(TreeNode * pRoot1, TreeNode * pRoot2){
        if(pRoot2 == NULL) return true;
        if(pRoot1 == NULL) return false;
        if(pRoot1->val != pRoot2->val) return false;
        
        return isEqual(pRoot1->left, pRoot2->left) && isEqual(pRoot1->right, pRoot2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL) return false;
        bool ans = false;
        if(pRoot1->val == pRoot2->val) ans = isEqual(pRoot1, pRoot2);
        if(!ans) ans = HasSubtree(pRoot1->left, pRoot2);
        if(!ans) ans = HasSubtree(pRoot1->right, pRoot2);
        
        return ans;
    }
};