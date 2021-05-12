#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

using pNode = struct TreeNode*;
struct TreeNode{
    int val;
    pNode left,right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
    
};

unordered_map<int,int> hashMap;

void Print(const vector<int>&vec)
{
    int n = vec.size();
    for(int i = 0;i<n;++i)
    {
        printf("%d",vec[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void Read(vector<int>&preorder,vector<int>&inorder)
{
    int n = 0;
    scanf("%d",&n);
    stack<int>stk;
    
    for(int i = 0;i<2*n;++i)
    {
        string op;
        cin>>op;
        if(op[1]=='u')
        {
            int num = 0;
            scanf("%d",&num);
            stk.push(num);
            preorder.push_back(num);
        }
        else
        {
            inorder.push_back(stk.top());
            stk.pop();
        }
    }
}

pNode buildTree(const vector<int>&preorder,int preLeft,int preRight,int inLeft,int inRight)
{
    if(inLeft>inRight)
    {
        return nullptr;
    }
    
    int val = preorder[preLeft];
    
    pNode root = new TreeNode(val);
    
    int inMid = hashMap[val];
    
    int length = inMid - inLeft;
    
    root->left = buildTree(preorder,preLeft+1,preLeft+length,inLeft,inMid-1);
    
    root->right = buildTree(preorder,preLeft+length+1,preRight,inMid+1,inRight);
    
    return root;
}

vector<int> postOrderTraversal(pNode root)
{
    stack<pNode>stk;
    pNode prev = nullptr;
    vector<int>result;
    
    while(!stk.empty()||root)
    {
        while(root)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if(root->right==nullptr||root->right==prev)
        {
            result.push_back(root->val);
            prev = root;
            root = nullptr;
        }
        else
        {
            stk.push(root);
            root = root->right;
        }
    }
    return result;
}

int main()
{
    vector<int>preorder;
    vector<int>inorder;
    
    Read(preorder,inorder);
    
    int n = preorder.size();
    
    for(int i = 0;i<n;++i)
    {
        hashMap[inorder[i]]=i;
    }
    
    pNode root = buildTree(preorder,0,n-1,0,n-1);
    
    vector<int>postorder = postOrderTraversal(root);
    
    Print(postorder);
    
    return 0;
}
