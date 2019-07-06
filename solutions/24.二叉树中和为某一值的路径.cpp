bool cmp(vector<int> & a, vector<int> & b){
        return a.size() > b.size();
    }
class Solution {
    void findPath(TreeNode * root, vector<vector<int>> & ans, vector<int> & path, int expectNumber, int pathSum){
        bool isLeafNode = (root->left == NULL && root->right == NULL);
        pathSum += root->val;
        path.push_back(root->val);
        if(pathSum == expectNumber && isLeafNode){
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        if(root->left != NULL) findPath(root->left, ans, path, expectNumber, pathSum);
        if(root->right != NULL) findPath(root->right, ans, path, expectNumber, pathSum);
        path.pop_back();
    }
    
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> ans;
        vector<int> path;
        if(root == NULL) return ans;
        findPath(root, ans, path, expectNumber, 0);
        sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};