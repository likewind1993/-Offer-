#include <iostream>
#include <string> 
using namespace std;

// class Solution {
//     string s;
//     void Serialize_(TreeNode * root, int & p)
//     {
//         if (root == NULL)
//         {
//             str[p++] = '#';
//             str[p++] = ',';
//             return;
//         }
//         str[p++] = root->val + '0';
//         str[p++] = ',';
//         Serialize_(root->left, p);
//         Serialize_(root->right, p);
//     }
//     TreeNode * Deserialize_(char *str, int & p)
//     {
//         char ch = str[p++];
//         if(ch == '#') {
//             ++p;
//             return NULL;
//         }
//         ch = ch-'0';
//         TreeNode * root = new TreeNode((int)ch);
//         ++p;
//         root->left = Deserialize_(str, p);
//         root->right = Deserialize_(str, p);
//         return root;
//     }

// public:
//     char* Serialize(TreeNode *root)
//     {
//         p = 0;
//         Serialize_(root ,p);
//         str[p] = '\0';
//         return str;

//     }
//     TreeNode* Deserialize(char *str)
//     {
//         if(str == NULL || str[0] == '#')
//             return NULL;
//         int p = 0;
//         return Deserialize_(str, p);
      
//     }
// };
int main() {
    cout<<"likewind"<<endl;

    return 0;
}