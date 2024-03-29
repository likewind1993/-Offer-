class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL) return ;
        
        TreeNode * temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};