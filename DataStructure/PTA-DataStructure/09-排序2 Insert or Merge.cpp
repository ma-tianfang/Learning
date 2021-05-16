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
    bool result = false;
    int N = nums.size();
    for(int P = 1;P<N;++P)
    {
        int j = P;
        int temp = nums[P];
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

void Merge(vector<int>&nums,vector<int>&tempNums,int L,int R,int RightEnd)
{
    int LeftEnd = R - 1;
    int temp = L;
    
    while(L<=LeftEnd&&R<=RightEnd)
    {
        if(nums[L]<nums[R])
        {
            tempNums[temp++] = nums[L++];
        }
        else
        {
            tempNums[temp++] = nums[R++];
        }
    }
    
    while(L<=LeftEnd)
    {
        tempNums[temp++] = nums[L++];
    }
    
    while(R<=RightEnd)
    {
        tempNums[temp++] = nums[R++];
    }
}

void merge_pass(vector<int>&nums,vector<int>&tempNums,int n,int length)
{
    int i = 0;
    for(;i<n-2*length;i+=2*length)
    {
        Merge(nums,tempNums,i,i+length,i+2*length-1);
    }
    if(i+length<n)
    {
        Merge(nums,tempNums,i,i+length,n-1);
    }
    else
    {
        for(int j = i;j<n;++j)
        {
            tempNums[j] = nums[j];
        }
    }
}

void merge_sort(vector<int>nums,const vector<int>&prev)
{
    int n = nums.size();
    vector<int>tempNums(n);
    int length = 1;
    bool result = false;
    
    while(length<n)
    {
        merge_pass(nums,tempNums,n,length);
        length*=2;
        if(compare(tempNums,prev))
        {
            result = true;
        }
        else if(result)
        {
            printf("Merge Sort\n");
            Print(tempNums);
            break;
        }
        merge_pass(tempNums,nums,n,length);
        length*=2;
        if(compare(nums,prev))
        {
            result = true;
        }
        else if(result)
        {
            printf("Merge Sort\n");
            Print(nums);
            break;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    
    vector<int>nums;
    vector<int>prev;
    
    Read(nums,n);
    Read(prev,n);
    
    if(!insertion_sort(nums,prev))
    {
        merge_sort(nums,prev);
    }
    
    return 0;
}
