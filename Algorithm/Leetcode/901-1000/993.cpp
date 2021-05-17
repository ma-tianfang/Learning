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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        int depth_x = 0,depth_y = 0;
        TreeNode *father_x=nullptr,*father_y=nullptr;
        int depth = 0;

        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0;i<n;++i)
            {
                root = q.front();
                q.pop();
                if(root->val==x)
                {
                    depth_x=depth;
                }
                else if(root->val==y)
                {
                    depth_y=depth;
                }
                if(root->left)
                {
                    q.push(root->left);
                    if(root->left->val==x)
                    {
                        father_x = root;
                    }
                    else if(root->left->val==y)
                    {
                        father_y = root;
                    }
                }
                if(root->right)
                {
                    q.push(root->right);
                    if(root->right->val==x)
                    {
                        father_x = root;
                    }
                    else if(root->right->val==y)
                    {
                        father_y = root;
                    }
                }
            }
            depth+=1;
        }
        return (depth_x==depth_y)&&(father_x!=father_y);
    }
};
