#include <iostream>
#include <stack>

using namespace std;

void judge(const int &m,const int &n)
{
    bool result = true;
    stack<int>stk;
    int count = 1;

    for(int i = 0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        // 读完剩余数字
        if(result)
        {
            // 堆栈为空或者栈顶元素不等于num，入栈
            while(stk.empty()||stk.top()!=num)
            {
                stk.push(count++);
                // 超过限制容量，break
                if(stk.size()>m)
                {
                    result = false;
                    break;
                }
            }
            // 堆栈不空且栈顶元素等于num，出栈
            if(stk.size()>=1&&stk.top()==num)
            {
                stk.pop();
            }
        }
    }
    if(result)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

int main()
{
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    
    for(int i = 0;i<k;++i)
    {
        judge(m,n);
    }
    
    return 0;
}
