class Solution {
public:
    bool isSame(TreeNode* pLeft, TreeNode* pRight){
        if(pLeft == pRight) return true;
        if(pLeft == NULL || pRight == NULL) return false;
        if(pLeft != NULL && pRight != NULL && pLeft->val != pRight->val) return false;
        return isSame(pLeft->left, pRight->right) && isSame(pLeft->right, pRight->left);
    }
    
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL) return true;
        return isSame(pRoot->left, pRoot->right);
    }

};