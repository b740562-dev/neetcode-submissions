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
    vector<int> rightSideView(TreeNode* root) {
        // if we take a queue then level wise we just need to process our last element of level 
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                level.push_back(curr->val);
            }
            ans.push_back(level[0]);
        }
        return ans;
    }
};
