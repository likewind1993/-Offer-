class Solution {
    void visitTree(TreeNode * root, int cur_depth, int & ans){
        if(root == NULL){
            ans = max(cur_depth, ans);
            return ;
        }
        visitTree(root->left, cur_depth + 1, ans);
        visitTree(root->right, cur_depth + 1, ans);
    }
public:
    int TreeDepth(TreeNode* pRoot)
    {
        int ans = 0;
        visitTree(pRoot, 0, ans);
        
        return ans;
    }
};