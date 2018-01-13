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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	TreeNode* root = new TreeNode(0);
        return(sortedArrayToBST(root, nums, 0, nums.size()-1));
    }
private:
	TreeNode* sortedArrayToBST(TreeNode* root, vector<int> &nums, int start, int end){
		int size = (end - start);
		if(size<0) return NULL;
		if(size==0) return (new TreeNode(nums[start]));

		int middle = (start+end+1)/2;

		root = new TreeNode(nums[middle]);
        // root->val = nums[middle];
		root->left = sortedArrayToBST(root->left, nums, start, middle-1);
		root->right = sortedArrayToBST(root->right, nums, middle+1, end);
        return root;
	}
};