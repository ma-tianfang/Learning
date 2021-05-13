#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int Read(vector<pair<int,int>>&cor)
{
    int n,d;
    scanf("%d %d",&n,&d);
    
    for(int i = 0;i<n;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        cor.push_back({x,y});
    }
    
    return d;
}

bool FirstJump(const int &x,const int &y,const int &d)
{
    return sqrt(x*x+y*y)<=d+15;
}

bool IsSafe(const int &x,const int &y,const int &d)
{
    return abs(x)+d>=50||abs(y)+d>=50;
}

bool CanJump(const int &x1,const int &y1,const int &x2,const int &y2,const int &d)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))<=d;
}

bool DFS(const int &num,vector<int>&visited,const int &n,const int &d,const vector<pair<int,int>>&cor)
{
    visited[num]=1;
    int x = cor[num].first,y = cor[num].second;
    bool answer = false;
    if(IsSafe(x,y,d))
    {
        answer = true;
    }
    else
    {
        for(int i = 0;i<n;++i)
        {
            if(!visited[i]&&CanJump(x,y,cor[i].first,cor[i].second,d))
            {
                answer = DFS(i,visited,n,d,cor);
            }
            if(answer)
            {
                break;
            }
        }
    }
    return answer;
}

int main()
{
    vector<pair<int,int>>cor;
    
    int d = Read(cor);
    int n = cor.size();
    vector<int>visited(n,0);
    
    bool answer = false;
    
    for(int i = 0;i<n;++i)
    {
        if(!visited[i]&&FirstJump(cor[i].first,cor[i].second,d))
        {
            answer = DFS(i,visited,n,d,cor);
        }
        if(answer)
        {
            break;
        }
    }
    
    printf("%s\n",answer?"Yes":"No");
    
    return 0;
}
