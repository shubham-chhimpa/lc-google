//https://leetcode.com/problems/find-leaves-of-binary-tree/


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
    
    int getHeight(TreeNode* root,vector<vector<int>> &ans){
        if(root==NULL) return -1;
        int left = getHeight(root->left,ans);
        int right = getHeight(root->right,ans);
        
        int curr = 1+max(left,right);
        if(ans.size() == curr){
            ans.push_back({});
        }
        ans[curr].push_back(root->val);
        return curr;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        getHeight(root,ans);
        return ans;
    }
};
