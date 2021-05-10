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
    void inorderTraversal(TreeNode*root,vector<int>&inorder)
    {
        stack<TreeNode*>stk;
        while(root||!stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root=root->left;
            }
            root = stk.top();
            stk.pop();
            if(!root->left&&!root->right)
            {
                inorder.push_back(root->val);
            }
            root = root->right;
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>l1;
        vector<int>l2;
        bool result = true;

        inorderTraversal(root1,l1);
        inorderTraversal(root2,l2);

        if(l1.size()!=l2.size())
        {
            result = false;
        }
        else
        {
            for(int i = 0;i<l1.size();++i)
            {
                if(l1[i]!=l2[i])
                {
                    result = false;
                    break;
                }
            }
        }
        return result;
    }
};
