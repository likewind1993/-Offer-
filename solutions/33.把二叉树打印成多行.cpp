class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> ans;
            if(pRoot == NULL) return ans;
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty()){
                int n = q.size();
                vector<int> level;
                for(int i = 0; i<n; ++i){
                    TreeNode * p_node = q.front();
                    level.push_back(p_node->val);
                    if(p_node->left != NULL) q.push(p_node->left);
                    if(p_node->right != NULL) q.push(p_node->right);
                    q.pop();
                }
                ans.push_back(level);
            }
            return ans;
        }
    
};