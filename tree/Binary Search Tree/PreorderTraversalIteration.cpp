/*
 * @Author: Alex
 * @Date: 2020-09-21 13:53:16
 * @LastEditTime: 2020-09-21 13:53:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /Binary Search Tree/PreorderTraversal.cpp
 */
//leetcode #144
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
    vector<int> preorderTraversal(TreeNode* root) {
        //iteration
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node =st.top();
            st.pop();
            if(node!=NULL)
                result.push_back(node->val);
            else
                continue;
            st.push(node->right);
            st.push(node->left);
        }

        return result;
    }
};