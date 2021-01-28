class Solution {
private:
    int store = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL)return NULL;
        bstToGst(root -> right);
        store += root -> val;
        root -> val = store;
        bstToGst(root -> left);
        return root; 
    }
};
