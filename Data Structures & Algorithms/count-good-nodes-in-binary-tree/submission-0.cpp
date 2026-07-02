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
    int dfs(TreeNode* root,int maxi){
        if(root==nullptr){
            return 0;
        }
        int cnt=0;
        if(root->val>=maxi){
            maxi=root->val;
            cnt++;
        }
        cnt+=dfs(root->left,maxi);
        cnt+=dfs(root->right,maxi);

        return cnt;

    }
public:
    int goodNodes(TreeNode* root) {
        // max width of binary tree in balanced tree is O(N/2)
        // we have to check whether node ki value max value till now se bdi hai ya nhi---if yes 
        // then good node otherwise not !

        // we will do dfs
        return dfs(root,INT_MIN); 

    }
};
