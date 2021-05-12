#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    int left,right;
    TreeNode():val(0),left(-1),right(-1){}
    TreeNode(int v,int l,int r):val(v),left(l),right(r){}
};

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

int Input(vector<TreeNode>&tree,const int &N)
{
    vector<int>roots(N,1);
    for(int i = 0;i<N;++i)
    {
        char l,r;
        TreeNode t = TreeNode();
        t.val = i;
        scanf("\n%c %c",&l,&r);
        if(l!='-')
        {
            t.left = l-'0';
            roots[t.left]=0;
        }
        else
        {
            t.left = -1;
        }
        if(r!='-')
        {
            t.right = r-'0';
            roots[t.right]=0;
        }
        else
        {
            t.right = -1;
        }
        tree.push_back(t);
    }
    int root = 0;
    for(int i = 0;i<N;++i)
    {
        if(roots[i])
        {
            root = i;
            break;
        }
    }
    return root;
}

void levelTraversal(vector<TreeNode>&tree,int root)
{
    queue<int>q;
    q.push(root);
    vector<int>result;
    
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0;i<n;++i)
        {
            root = q.front();
            q.pop();
            if(tree[root].left!=-1)q.push(tree[root].left);
            if(tree[root].right!=-1)q.push(tree[root].right);
            if(tree[root].left==-1&&tree[root].right==-1)
            {
                result.push_back(root);
            }
        }
    }
    
    Print(result);
}

int main()
{
    int N;
    scanf("%d",&N);
    
    vector<TreeNode>tree;
    
    int root = Input(tree,N);

    // 中序遍历
    levelTraversal(tree,root);
    
    return 0;
}
