#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int,int>hashMap;

int main()
{
    int N;
    scanf("%d",&N);
    vector<int>nums;
    
    for(int i = 0;i<N;++i)
    {
        int num;
        scanf("%d",&num);
        hashMap[num]+=1;
        if(find(nums.begin(),nums.end(),num)==nums.end())
        {
            nums.push_back(num);
        }
    }
    
    sort(nums.begin(),nums.end());
    
    for(auto num:nums)
    {
        printf("%d:%d\n",num,hashMap[num]);
    }
    
    return 0;
}
