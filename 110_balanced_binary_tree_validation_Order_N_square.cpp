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
        if(root ==NULL){
            return 0;
        }    
        else{
            return(max(depth(root->left), depth(root->right))+1);
        }
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        else{
            int leftHeight = depth(root->left);
            int rightHeight = depth(root->right);
            
            return(abs(leftHeight-rightHeight) <2 && isBalanced(root->left) && isBalanced(root->right));
        }
    }
};