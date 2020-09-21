/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int  num= 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        

        if(root!=nullptr){
        
            convertBST(root->right);

            root->val = root->val + num;
            num = root->val;
            
            convertBST(root->left);
            return root;
        }
        return nullptr;
    }
};