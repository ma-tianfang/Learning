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

void Read(vector<int>&nums,const int &n)
{
    for(int i = 0;i<n;++i)
    {
        int num;
        scanf("%d",&num);
        nums.push_back(num);
    }
}

bool compare(const vector<int>&vec1,const vector<int>&vec2)
{
    int n = vec1.size();
    for(int i = 0;i<n;++i)
    {
        if(vec1[i]!=vec2[i])
        {
            return false;
        }
    }
    return true;
}

bool insertion_sort(vector<int>nums,const vector<int>&prev)
{
    int n = nums.size();
    bool result = false;
    
    for(int i = 1;i<n;++i)
    {
        int temp = nums[i];
        int j = i;
        for(;j>0&&nums[j-1]>temp;--j)
        {
            nums[j] = nums[j-1];
        }
        nums[j]=temp;
        if(compare(nums,prev))
        {
            result = true;
        }
        else if(result)
        {
            printf("Insertion Sort\n");
            Print(nums);
            break;
        }
    }
    
    return result;
}

void PercDown(vector<int>&nums,int top,int n)
{
    int temp = nums[top];
    int parent = top,child = 0;
    for(;2*parent+1<n;parent = child)
    {
        child = 2*parent+1;
        if(child+1<n&&nums[child+1]>nums[child])
        {
            child+=1;
        }
        if(nums[child]<temp)
        {
            break;
        }
        nums[parent] = nums[child];
    }
    nums[parent] = temp;
}

void heap_sort(vector<int>&nums,const vector<int>&prev)
{
    int n = nums.size();
    bool result = false;
    
    for(int i = n/2;i>=0;--i)
    {
        PercDown(nums,i,n);
    }
    for(int i = n-1;i>0;--i)
    {
        swap(nums[0],nums[i]);
        PercDown(nums,0,i);
        if(compare(nums,prev))
        {
            result = true;
        }
        else if(result)
        {
            printf("Heap Sort\n");
            Print(nums);
            break;
        }
        
    }
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    
    vector<int>nums;
    vector<int>prev;
    
    Read(nums,n);
    Read(prev,n);
    
    if(!insertion_sort(nums,prev))
    {
        heap_sort(nums,prev);
    }
    
    return 0;
}
