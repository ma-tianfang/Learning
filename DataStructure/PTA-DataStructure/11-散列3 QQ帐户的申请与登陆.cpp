// unordered_map
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string,string>hashMap;

int main()
{
    int N = 0;
    scanf("%d",&N);
    
    for(int i = 0;i<N;++i)
    {
        char op;
        scanf("\n%c",&op);
        
        string user,pw;
        cin>>user>>pw;
        
        if(op=='L')
        {
            // login
            if(hashMap.find(user)==hashMap.end())
            {
                printf("ERROR: Not Exist");
            }
            else if(hashMap[user]!=pw)
            {
                printf("ERROR: Wrong PW");
            }
            else
            {
                printf("Login: OK");
            }
        }
        else if(op=='N')
        {
            // new
            if(hashMap.find(user)==hashMap.end())
            {
                hashMap[user]=pw;
                printf("New: OK");
            }
            else
            {
                printf("ERROR: Exist");
            }
        }
        printf("\n");
    }
    
    return 0;
}
