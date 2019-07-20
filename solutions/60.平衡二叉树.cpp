#include "Tree.hpp"
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
    int calc_depth(TreeNode * root)
    {
        if (root == NULL)
            return 0;
        return max(calc_depth(root->left) + 1, calc_depth(root->right) + 1);
    }

public:
    bool IsBalanced_Solution(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return true;
        int left_depth = calc_depth(pRoot->left), right_depth = calc_depth(pRoot->right);
        if(abs(left_depth - right_depth) > 1)
            return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};
int main() {
    Solution solution;
    TreeNode * root = createTree();
    cout<<solution.IsBalanced_Solution(root)<<endl;

    return 0;
}