class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * p_node = q.front();
            ans.push_back(p_node->val);
            q.pop();
            if(p_node->left != NULL) q.push(p_node->left);
            if(p_node->right != NULL) q.push(p_node->right);
        }
        return ans;
    }
};