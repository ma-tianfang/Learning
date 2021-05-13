#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
private:
    
public:
    int nv,ne;
    vector<vector<int>>graph;
    
    Graph(int n):nv(n)
    {
        for(int i =0;i<n;++i)
        {
            graph.push_back(vector<int>(n,0));
        }
    }
    
    void InsertEdge(int x,int y);
    void ListElements(int flag);
    void DFS(int node,vector<int>&result,vector<int>&visited);
    void BFS(int node,vector<int>&result,vector<int>&visited);
    void Print(const vector<int>&vec);
};

void Graph::InsertEdge(int x,int y)
{
    graph[x][y]=1;
    graph[y][x]=1;
}

void Graph::Print(const vector<int>&vec)
{
    int n = vec.size();
    printf("{ ");
    for(int i =0;i<n;++i)
    {
        printf("%d ",vec[i]);
    }
    printf("}\n");
}

void Graph::DFS(int node,vector<int>&result,vector<int>&visited)
{
    visited[node]=1;
    result.push_back(node);
    
    for(int i = 0;i<nv;++i)
    {
        if(!visited[i]&&graph[node][i]==1)
        {
            DFS(i,result,visited);
        }
    }
}

void Graph::BFS(int node,vector<int>&result,vector<int>&visited)
{
    queue<int>q;
    q.push(node);
    
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0;i<n;++i)
        {
            node = q.front();
            result.push_back(node);
            visited[node]=1;
            q.pop();
            for(int j = 0;j<nv;++j)
            {
                if(!visited[j]&&graph[node][j])
                {
                    visited[j]=1;
                    q.push(j);
                }
            }
        }
    }
}

void Graph::ListElements(int flag)
{
    vector<int>visited(nv,0);
    vector<int>result;
    
    for(int i = 0;i<nv;++i)
    {
        if(!visited[i])
        {
            result.clear();
            if(flag==0)
            {
                DFS(i,result,visited);
            }
            else if(flag==1)
            {
                BFS(i,result,visited);
            }
            Print(result);
        }
    }
}

Graph Read()
{
    int n,e;
    scanf("%d %d",&n,&e);
    
    Graph g = Graph(n);
    
    for(int i = 0;i<e;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        g.InsertEdge(x,y);
    }
    
    return g;
}

int main()
{
    Graph g = Read();
    
    // DFS
    g.ListElements(0);
    
    //BFS
    g.ListElements(1);
    
    return 0;
}
