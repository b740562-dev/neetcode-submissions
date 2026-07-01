/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    //   apply bfs to actually visit every left node every right node and reverse them 
        if(root==nullptr){
            return root;
        }
        // invert root ka left and right and call this for again left and right !!
        TreeNode* left=root->left;
        root->left=root->right;
        root->right=left;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
