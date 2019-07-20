#include "Tree.hpp"
#include "List.hpp"

class Solution {
private:
    TreeNode * p_head = NULL;
    void Visited(TreeNode * root, TreeNode ** last_node)
    {
        if (root == NULL)
            return;
        Visited(root->left, last_node);
        if ((*last_node) != NULL)
            (*last_node)->right = root;
        else
            p_head = root;
        root->left = (*last_node);
        (*last_node) = root;
        Visited(root->right, last_node);
    }


public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode * last_node = NULL;
        Visited(pRootOfTree, &last_node);
        return p_head;
    }
};
void print_right_child(TreeNode * root){
    while(root != NULL){
        std::cout<<root->val<<std::endl;
        root = root->right;
    }
}

int main() {
    Solution solution;

    TreeNode * root = createTree();
    TreeNode * p_head = solution.Convert(root);
    print_right_child(p_head);
    return 0;
}