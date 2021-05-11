#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x7ffffff;

int main()
{
    int n = 0;
    scanf("%d",&n);
    vector<int>nums;
    
    int start = 0,end = 0;
    int result = -INF,curr = 0,prev = 0;
    
    for(int i = 0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        
        nums.push_back(num);
        
        curr+=num;
        if(curr>result)
        {
            result = curr;
            end = i;
            start = prev;
        }
        if(curr<0)
        {
            curr = 0;
            prev = i+1;
        }
    }
    
    if(result<0)
    {
        printf("0 %d %d\n",nums[0],nums[n-1]);
    }
    else
    {
        printf("%d %d %d\n",result,nums[start],nums[end]);
    }
    
    return 0;
}
