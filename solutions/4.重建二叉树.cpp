class Solution {
public:
    int findIndex(vector<int> & vin, int val)
    {
        for(int i = 0; i<vin.size(); ++i) {
            if(vin[i] == val) return i;
        }
        return - 1;
    }
    TreeNode* createTree(vector<int>& pre, vector<int>& vin, int& cur_pos, int left, int right)
    {
        if (cur_pos >= pre.size() || left > right) {
            if(left > right) cur_pos -= 1;
            return NULL;
        }
        if (left == right)
            return new TreeNode(pre[cur_pos]);
        TreeNode * root = new TreeNode(pre[cur_pos]);
        int index = findIndex(vin, pre[cur_pos]);
        cur_pos += 1;
        root->left = createTree(pre, vin, cur_pos, left, index - 1);
        cur_pos += 1;
        root->right = createTree(pre, vin, cur_pos, index + 1, right);
        return root;
    }

    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.empty())
            return NULL;
        int cur_pos = 0;
        TreeNode * root = createTree(pre, vin, cur_pos, 0, pre.size() - 1);
        return root;
    }
};