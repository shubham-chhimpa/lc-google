//https://leetcode.com/problems/correct-a-binary-tree/

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
    TreeNode* correctBinaryTree(TreeNode* root) {
             unordered_set<TreeNode*> s;
        
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        
        while(!q.empty()){
            auto p = q.front();
            auto curr = p.first;
            q.pop();
          
            s.insert(curr);
            if(curr->right){
                if(s.find(curr->right) != s.end()){
                    curr->right = NULL;
                    auto parent = p.second;
                    if(parent->left && parent->left == curr){
                        parent->left = NULL;
                    }else{
                        parent->right = NULL;
                    }
                    break;
                }
        
                q.push({curr->right,curr});
            }

            if(curr->left){
                q.push({curr->left,curr});
            }
        }    
        
        return root;
    }
};
