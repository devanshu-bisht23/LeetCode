/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool mirror(struct TreeNode* left, struct TreeNode* right){

if (left==NULL && right==NULL) return true;
if (left==NULL || right==NULL) return false;

if(left->val!=right->val) return false;

return mirror(left->left,right->right) && mirror(left->right,right->left);


}

bool isSymmetric(struct TreeNode* root) {

if (root==NULL) return true;

bool x = mirror(root->left, root->right);

if(x==true)
    return true;
else
    return false;
}