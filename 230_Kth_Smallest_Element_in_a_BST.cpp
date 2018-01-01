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
    int findNumElements(TreeNode* root){
        if(root==NULL)  return 0;
        
        return(findNumElements(root->left) + findNumElements(root->right) + 1);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return 0;
        int numElementsLeft = findNumElements(root->left);
        if(k<numElementsLeft+1){
            return kthSmallest(root->left, k);
        }
        else if (k == numElementsLeft+1){
            return root->val;
        }
        else{
            return kthSmallest(root->right, k-numElementsLeft-1);
        }
    }
};