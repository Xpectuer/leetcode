/*
 * @Author: your name
 * @Date: 2020-09-21 15:14:45
 * @LastEditTime: 2020-09-21 15:15:19
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /leetcode/tree/Binary Search Tree/538iter.cpp
 */
//iteration

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
public:
    TreeNode* convertBST(TreeNode* root) {
        int num=0;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(node!=NULL||!st.empty()){
            if(node!=NULL){
                st.push(node);
                node = node->right;          //right
            }
            
            else{
                node = st.top();
                st.pop();

                node ->val += num;
                num = node->val;//  modify the mid
                
                node =node ->left;

            }

       

        }
         return root;


    }
};