#include <iostream>
#include <unordered_map>

using namespace std;

using pNode = struct Node*;
struct Node{
    int address;
    int data;
    int next;
    pNode nex;
    Node():address(0),data(0),next(0),nex(nullptr){}
    Node(int a,int d,int e):address(a),data(d),next(e),nex(nullptr){}
};

pNode Read(const int &n,const int &start)
{
    unordered_map<int,pNode>vec;
    for(int i = 0;i<n;++i)
    {
        int a,d,e;
        scanf("%d %d %d",&a,&d,&e);
        vec[a]=new Node(a,d,e);
    }
    pNode s = new Node(),ps = s;
    int end = start;
    while(end!=-1)
    {
        s->nex = vec[end];
        s=s->nex;
        end = s->next;
    }
    return ps;
}

void Print(pNode p)
{
    if(!p)
    {
        return;
    }
    p=p->nex;
    while(p)
    {
        printf("%05d %d ",p->address,p->data);
        if(p->next!=-1)
        {
            printf("%05d",p->next);
        }
        else
        {
            printf("-1");
        }
        printf("\n");
        p = p->nex;
    }
}

pair<pNode,pNode>reverse(pNode head,pNode tail)
{
    pNode prev = tail->nex,curr = head;
    while(prev!=tail)
    {
        pNode temp = curr->nex;
        curr->nex=prev;
        if(prev)
        {
            curr->next = prev->address;
        }
        else
        {
            curr->next = -1;
        }
        prev = curr;
        curr = temp;
    }
    return {tail,head};
}

void reverseK(pNode head,const int &k)
{
    pNode pHead = head->nex,prev = head;
    while(pHead)
    {
        int count = 1;
        pNode tail = pHead;
        while(tail&&count<k)
        {
            tail = tail->nex;
            count+=1;
        }
        if(count!=k||!tail)
        {
            break;
        }
        pair<pNode,pNode>result = reverse(pHead,tail);
        prev->nex = result.first;
        prev->next = result.first->address;
        prev = result.second;
        pHead = prev->nex;
    }
}

int main()
{
    int start,n,k;
    scanf("%d %d %d",&start,&n,&k);
    
    pNode head = Read(n,start);
    
    reverseK(head,k);
    
    Print(head);
    
    return 0;
}
