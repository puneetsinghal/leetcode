/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode *root){
        if(root == NULL)    return 0;
        
        int leftDepth = depth(root->left);
        if(leftDepth == -1) return -1;
        
        int rightDepth = depth(root->right);
        if(rightDepth == -1) return -1;
        
        if(abs(leftDepth - rightDepth)>1)   return -1;
        
        else    return(max(leftDepth, rightDepth)+1);
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        if(depth(root)==-1)
            return false;
        else{
            return true;
        }
    }
};