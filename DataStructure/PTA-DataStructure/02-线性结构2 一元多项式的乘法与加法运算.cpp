#include <iostream>

using namespace std;

using pPolyNode = struct PolyNode*;
struct PolyNode{
    int coef;
    int expon;
    pPolyNode next;
    PolyNode():coef(0),expon(0),next(nullptr){}
    PolyNode(int c,int e):coef(c),expon(e),next(nullptr){}
    PolyNode(int c,int e,pPolyNode nex):coef(c),expon(e),next(nex){}
};

void Print(pPolyNode head)
{
    head = head->next;
    if(!head)
    {
        printf("0 0");
    }
    else
    {
        while(head)
        {
            printf("%d %d",head->coef,head->expon);
            if(head->next)
            {
                printf(" ");
            }
            head=head->next;
        }
    }
    printf("\n");
}

void Attach(int c,int e,pPolyNode *p)
{
    if(c==0)
    {
        return ;
    }
    pPolyNode temp = new PolyNode(c,e);
    (*p)->next = temp;
    (*p) = (*p)->next;
}

pPolyNode PolyAdd(pPolyNode p1,pPolyNode p2)
{
    pPolyNode head = new PolyNode(),pHead = head;
    p1 = p1->next;
    p2 = p2->next;
    while(p1&&p2)
    {
        if(p1->expon==p2->expon)
        {
            int sum = p1->coef + p2->coef;
            if(sum)
            {
                Attach(sum,p1->expon,&head);
            }
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->expon>p2->expon)
        {
            Attach(p1->coef,p1->expon,&head);
            p1=p1->next;
        }
        else
        {
            Attach(p2->coef,p2->expon,&head);
            p2=p2->next;
        }
    }
    head->next = p1?p1:p2;
    return pHead;
}

pPolyNode PolyMul(pPolyNode p1,pPolyNode p2)
{
    pPolyNode head = new PolyNode();
    pPolyNode pHead = head;
    pPolyNode ret = new PolyNode();
    // 去除头结点
    p1=p1->next;
    p2=p2->next;
    
    while(p1)
    {
        pPolyNode p = p2;
        while(p)
        {
            Attach(p->coef*p1->coef,p->expon+p1->expon,&head);
            p=p->next;
        }
        ret = PolyAdd(pHead,ret);
        head = pHead;
        p1=p1->next;
    }
    
    return ret;
}

pPolyNode Read()
{
    int n = 0;
    scanf("%d",&n);
    pPolyNode pHead = new PolyNode(),head = pHead;
    
    for(int i = 0;i<n;++i)
    {
        int c,e;
        scanf("%d %d",&c,&e);
        Attach(c,e,&head);
    }
    return pHead;
}

int main()
{
    pPolyNode p1 = Read();
    pPolyNode p2 = Read();
    
    pPolyNode pMul = PolyMul(p1,p2);
    
    Print(pMul);
    
    pPolyNode pAdd = PolyAdd(p1,p2);

    Print(pAdd);
    
    return 0;
}
