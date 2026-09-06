class Solution {
public:

    bool checkBST(TreeNode* root, long long minVal, long long maxVal) {

        if(root == NULL)
            return true;

        if(root->val <= minVal || root->val >= maxVal)
            return false;

        bool leftBST = checkBST(root->left, minVal, root->val);

        bool rightBST = checkBST(root->right, root->val, maxVal);

        return leftBST && rightBST;
    }

    bool isValidBST(TreeNode* root) {

        return checkBST(root, LLONG_MIN, LLONG_MAX);
    }
};