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
    int height(TreeNode* root,int& maxi){
        if(root==nullptr){
            return 0;
        }
        // for a given node 
        int left=height(root->left,maxi);
        int right=height(root->right,maxi);
        int currmax=max(root->val,max(root->val+left,root->val+right));
        maxi=max(maxi,max(root->val+left+right,currmax));
        return currmax;
    }
public:
    int maxPathSum(TreeNode* root) {
        // max path same can be written as we find diameter of binary tree in the maxdepth finding q'
        int maxi=INT_MIN;
        height(root,maxi);
        return maxi; 
    }
};
