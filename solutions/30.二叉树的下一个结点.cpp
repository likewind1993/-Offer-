class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        TreeLinkNode * next_node = NULL;
        if(pNode->right != NULL){
            TreeLinkNode * right_node = pNode->right;
            while(right_node->left!=NULL) 
                right_node = right_node->left;
            next_node = right_node;
        }else if(pNode->next != NULL){
            TreeLinkNode * parent_node = pNode->next;
            TreeLinkNode * cur_node = pNode;
            if( cur_node == parent_node->left){
                next_node = parent_node;
            }else {
                while(parent_node != NULL && cur_node == parent_node->right){
                    cur_node = parent_node;
                    parent_node = parent_node->next;
                }
                next_node = parent_node;
            }
        }
        return next_node;
    }
};