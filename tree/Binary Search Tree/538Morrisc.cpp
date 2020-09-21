/*
 * @Author: your name
 * @Date: 2020-09-21 15:17:24
 * @LastEditTime: 2020-09-21 16:53:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcode/tree/Binary Search Tree/538Morrisc.cpp
 */
//Morris
// O(1) Space Complexity
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

class Solution {
public:
    TreeNode* getPredecessor(TreeNode* node) {
        //Discard the stack to find the predecessor

        //Get the most left node of  right sub-trees as the predecessor
        TreeNode* pred = node->right;
        while (pred->left != nullptr && pred->left != node) {
            pred = pred->left;
        }
        return pred;
    }

    TreeNode* convertBST(TreeNode* root) {
        
        int sum = 0;

        //Initialise
        TreeNode* node = root;
        //
        TreeNode* pred;

        while (node != nullptr) {
            if (node->right == nullptr) {
                //Process the node
                sum += node->val;
                node->val = sum;
                //Proceed to the left node
                node = node->left;
            
            } else {
                //Get the most left node of  right sub-trees as the predecessor
                pred = getPredecessor(node);
                
                //connect the predecessor with the node to keep the predecessor
                if (pred->left == nullptr) {
                    pred->left = node;
                    // move node to the right node
                    node = node->right;
                } else {
                    // discard the link
                    pred->left = nullptr;
                    //process the node
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }

        return root;
    }
};
