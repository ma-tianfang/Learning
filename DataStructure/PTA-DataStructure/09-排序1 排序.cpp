#include <iostream>
#include <vector>

using namespace std;

void Print(const vector<int>&nums)
{
    int n = nums.size();
    
    for(int i = 0;i<n;++i)
    {
        printf("%d",nums[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int getPivot(vector<int>&nums,int left,int right)
{
    int center = (left+right)>>1;
    if(nums[left]>nums[center])
    {
        swap(nums[left],nums[center]);
    }
    if(nums[left]>nums[right])
    {
        swap(nums[left],nums[right]);
    }
    if(nums[center]>nums[right])
    {
        swap(nums[center],nums[right]);
    }
    swap(nums[center],nums[right-1]);
    return nums[right - 1];
}

void Qsort(vector<int>&nums,int l,int r)
{
    if(r-l>0)
    {
        int pivot = getPivot(nums,l,r);
        int left = l,right = r - 1;
        while(left<right)
        {
            while(nums[--right]>pivot);
            while(nums[++left]<pivot);
            if(left<right)
            {
                swap(nums[left],nums[right]);
            }
        }
        swap(nums[left],nums[r-1]);
        Qsort(nums,l,left-1);
        Qsort(nums,left+1,r);
    }
}

void quick_sort(vector<int>&nums)
{
    int n = nums.size();
    Qsort(nums,0,n-1);
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    vector<int>nums;
    
    for(int i = 0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        nums.push_back(num);
    }
    
    quick_sort(nums);
    
    Print(nums);
    
    return 0;
}
