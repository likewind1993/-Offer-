#include <iostream>
//树节点的定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//以先序遍历手动输入创建树，-1表示空节点
TreeNode *createTree()
{
    int val = 0;
    std::cin >> val;
    TreeNode *root = NULL;
    if (val != -1)
    {
        root = new TreeNode(val);
        root->left = createTree();
        root->right = createTree();
    }

    return root;
}
//先序遍历输出树结构
void printTree(TreeNode *root)
{
    if (root == NULL)
        return;
    std::cout << root->val << std::endl;
    printTree(root->left);
    printTree(root->right);
}