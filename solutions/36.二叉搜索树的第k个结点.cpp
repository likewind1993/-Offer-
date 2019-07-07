class Solution {
    void findKthNode(TreeNode * root, TreeNode ** ans, int & count, int k)
    {
        if (root == NULL || count > k) return;
        findKthNode(root->left, ans, count, k);
        if (++count == k)
        {
            *ans = root;
            return;
        }
        findKthNode(root->right, ans, count, k);
    }

public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == NULL) return NULL;
        TreeNode * ans = NULL;
        int count = 0;
        findKthNode(pRoot, &ans, count, k);
        return ans;
    }
};