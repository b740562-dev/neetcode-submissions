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
    void dfs(TreeNode* root,int depth,vector<int>& ans){
        if(root==nullptr){
            return;
        }
        // if depth = ans ka size then only push element !!!
        if(depth==ans.size()){
            ans.push_back(root->val);
        }
        dfs(root->right,depth+1,ans);
        dfs(root->left,depth+1,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {

        // Can solve this problem by printing first element of each depth
        vector<int> ans;
        dfs(root,0,ans);
        return ans;
// ----------------------------BFS Traversal---------------------------------------------------
        // if we take a queue then level wise we just need to process our last element of level 
        // TC=O(N) -- every node is visited at once !!!
        // SC=O(W)----max width of tree !!!!
        
        // queue<TreeNode*> q;
        // q.push(root);

        // while(!q.empty()){
        //     int n=q.size();
        //     for(int i=0;i<n;i++){
        //         TreeNode* curr=q.front();
        //         q.pop();
        //         if(i==0){
        //             ans.push_back(curr->val);
        //         }
        //         if(curr->right!=nullptr){
        //             q.push(curr->right);
        //         }
        //         if(curr->left!=nullptr){
        //             q.push(curr->left);
        //         }
        //     }
        // }
        // return ans;
    }
};
