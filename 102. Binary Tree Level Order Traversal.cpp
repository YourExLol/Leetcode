## Problem Statement ##
## 102. Binary Tree Level Order Traversal
## https://leetcode.com/problems/binary-tree-level-order-traversal/

############################################### Code begins here ##############################################################

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int count=q.size();
            vector<int> v;
            
            for(int i=0;i<count;i++){
            TreeNode *f=q.front();
            v.push_back(f->val);
            q.pop();
            
            if(f->left!=NULL) q.push(f->left);
            if(f->right!=NULL) q.push(f->right);
            
            } //for ends here
            ans.push_back(v);
        }//while ends here
        return ans;
        
    }
};
