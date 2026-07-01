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
private: 
    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        
        int left=height(root->left);
        int right=height(root->right);


        if(left==-1 || right==-1 || abs(left-right)>1){
            return -1;
        }
        
        return 1+max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        // for every node we have to check height of it's left and right node ka difference !!
        if(root==nullptr){
            return 1;
        }
        int left=height(root->left);
        int right=height(root->right);
        if(left==-1 || right==-1 || abs(left-right)>1){
            return 0;
        }
        return 1;
    }
};
