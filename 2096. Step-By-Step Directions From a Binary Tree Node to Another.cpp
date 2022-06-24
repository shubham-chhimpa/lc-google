//https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

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
    TreeNode* lca(TreeNode* root, int startValue, int destValue){
        if(root==NULL) return NULL;
        if(root->val == startValue || root->val == destValue) return root;
        if(root->left==NULL and root->right == NULL) return NULL;
        TreeNode* left = lca(root->left,startValue,destValue);
        TreeNode* right = lca(root->right,startValue,destValue);
        if(left and right) return root;
        return left==NULL?right:left;
    }
    
    bool find_path(TreeNode* root,int target,string &p){
        if(root==NULL) return false;
        if(root->val==target) return true;
        p.push_back('L');
        if(find_path(root->left,target,p)) return true;
        p.pop_back();
        p.push_back('R');
        if(find_path(root->right,target,p)) return true;
         p.pop_back();
        return false;
    }
    

    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode* common = lca(root,startValue,destValue);
        cout<<common->val<<"\n";
        string p1,p2;
        find_path(common,startValue,p1);
        find_path(common,destValue,p2);
        for(auto &c : p1) c='U';
        return p1+p2;

    }
};
