#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    char val;
    int left,right;
    TreeNode():val('A'),left(-1),right(-1){}
};

int ReadTree(vector<TreeNode>&tree)
{
    int N = 0;
    scanf("%d",&N);
    
    vector<int>roots(N,1);
    for(int i=0;i<N;++i)
    {
        TreeNode t = TreeNode();
        char l,r;
        scanf("\n%c %c %c",&(t.val),&l,&r);
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
    int root = -1;
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

bool Isomorphic(const int &root1,vector<TreeNode>&t1,const int &root2,vector<TreeNode>&t2)
{
    if(root1==-1&&root2==-1)
    {
        return true;
    }
    if((root1==-1&&root2!=-1)||(root1!=-1&&root2==-1))
    {
        return false;
    }
    if(t1[root1].val!=t2[root2].val)
    {
        return false;
    }
    if(t1[root1].left==-1&&t2[root2].left==-1)
    {
        return Isomorphic(t1[root1].right,t1,t2[root2].right,t2);
    }
    // 不需要旋转
    if((t1[root1].left!=-1&&t2[root2].left!=-1)&&(t1[t1[root1].left].val==t2[t2[root2].left].val))
    {
        return (Isomorphic(t1[root1].left,t1,t2[root2].left,t2)&&Isomorphic(t1[root1].right,t1,t2[root2].right,t2));
    }
    else
    {
        return (Isomorphic(t1[root1].left,t1,t2[root2].right,t2)&&Isomorphic(t1[root1].left,t1,t2[root2].right,t2));
    }
}

int main()
{
    vector<TreeNode>t1;
    vector<TreeNode>t2;
    
    // 建树
    int root1 = ReadTree(t1);
    int root2 = ReadTree(t2);
    
    // 判断
    if(Isomorphic(root1,t1,root2,t2))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    
    return 0;
}
