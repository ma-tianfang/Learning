#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    scanf("%d",&n);
    int result = 0;
    int curr = 0;
    
    for(int i = 0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        curr+=num;
        if(curr>result)
        {
            result = curr;
        }
        if(curr<0)
        {
            curr=0;
        }
    }
    
    printf("%d\n",result);
    
    return 0;
}
