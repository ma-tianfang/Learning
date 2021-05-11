List Merge( List L1, List L2 )
{
    List L = (List)malloc(sizeof(List));
    List pL = L;
    List l1 = L1->Next,l2 = L2->Next;
    while(l1&&l2)
    {
        if(l1->Data<=l2->Data)
        {
            L->Next = l1;
            l1=l1->Next;
        }
        else
        {
            L->Next = l2;
            l2 = l2->Next;
        }
        L=L->Next;
    }
    if(l1)
    {
        L->Next = l1;
    }
    if(l2)
    {
        L->Next = l2;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return pL;
}
