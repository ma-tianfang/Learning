#include <iostream>
#include <string>
#include <vector>

using namespace std;

void BuildMatch(const string&pattern,vector<int>&match)
{
    int m = pattern.size();
    for(int j = 1;j<m;++j)
    {
        int i = match[j-1];
        while(i>=0&&pattern[i+1]!=pattern[j])
        {
            i = match[i];
        }
        if(pattern[i+1]==pattern[j])
        {
            match[j]=i+1;
        }
        else
        {
            match[j]=-1;
        }
    }
}

int KMP(const string &s,const string &pattern)
{
    int n = s.size();
    int m = pattern.size();
    int p1 = 0,p2 = 0;
    
    if(n<m)
    {
        return -1;
    }
    
    // 构建match辅助数组
    vector<int>match(m,-1);
    BuildMatch(pattern,match);
    
    while(p1<n&&p2<m)
    {
        if(s[p1]==pattern[p2])
        {
            p1+=1;
            p2+=1;
        }
        else if(p2>0)
        {
            p2 = match[p2-1]+1;
        }
        else
        {
            p1+=1;
        }
    }
    return p2==m?p1-m:-1;
}

// KMP算法
int main()
{
    string standard;
    int N = 0;
    
    cin>>standard;
    scanf("%d",&N);
    
    for(int i = 0;i<N;++i)
    {
        string pattern;
        cin>>pattern;
        int index = KMP(standard,pattern);
        if(index==-1)
        {
            printf("Not Found\n");
        }
        else
        {
            cout<<standard.substr(index)<<endl;
        }
    }
    
    return 0;
}
