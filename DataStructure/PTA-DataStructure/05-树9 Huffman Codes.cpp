#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

const int minData = 0;
unordered_map<char,int>hashMap;

// 树结构
using HuffmanTree = struct TreeNode*;
struct TreeNode{
    int weight;
    HuffmanTree left,right;
    TreeNode():weight(minData),left(nullptr),right(nullptr){}
    TreeNode(int w):weight(w),left(nullptr),right(nullptr){}
};

// ------------------------ 最小堆 ------------------------
// 求WPL
int WPL(HuffmanTree H,int depth)
{
    if(H->left==nullptr&&H->right==nullptr)
    {
        return H->weight*depth;
    }
    return WPL(H->left,depth+1)+WPL(H->right,depth+1);
}

// 交换
void swapNode(HuffmanTree&h1,HuffmanTree&h2)
{
    HuffmanTree h = h1;
    h1 = h2;
    h2 = h;
}

//删除
HuffmanTree Delete(vector<HuffmanTree>&heap)
{
    HuffmanTree H = heap[1];
    int N = heap.size();
    HuffmanTree huff = heap[N-1];
    heap.pop_back();
    N-=1;
    if(N>1)
    {
        int parent,child;
        for(parent = 1;2*parent<N;parent = child)
        {
            child = 2*parent;
            if(child+1<N&&heap[child+1]->weight<heap[child]->weight)
            {
                child+=1;
            }
            if(huff->weight<=heap[child]->weight)
            {
                break;
            }
            swapNode(heap[child],heap[parent]);
        }
        heap[parent] = huff;
    }
    return H;
}

// 插入
void Insert(HuffmanTree huff,vector<HuffmanTree>&heap)
{
    int n = heap.size();
    heap.push_back(huff);
    while(heap[n/2]->weight>heap[n]->weight)
    {
        heap[n] = heap[n/2];
        n/=2;
    }
    heap[n] = huff;
}

int InitMinHeap(vector<HuffmanTree>&heap)
{
    int N = 0;
    scanf("%d",&N);

    for(int i = 0;i<N;++i)
    {
        getchar();
        char c;
        int w;
        scanf("%c %d",&c,&w);
        hashMap[c]=w;
        Insert(new TreeNode(w),heap);
    }

    return N;
}

// ------------------------ Huffman Tree ------------------------ 
HuffmanTree InitHuffmanTree(vector<HuffmanTree>&heap)
{
    // 去掉哨兵
    int N = heap.size() - 1;
    // 合并执行n-1次
    for(int i = 1;i<N;++i)
    {
        HuffmanTree H = new TreeNode();
        H->left = Delete(heap);
        H->right = Delete(heap);
        H->weight = H->left->weight + H->right->weight;
        Insert(H,heap);
    }
    return Delete(heap);
}

// 判断
bool check(const int &N,const int &codeLength)
{
    bool flag = true;
    HuffmanTree H = new TreeNode();
    HuffmanTree pre;
    // 总结点数
    int counter = 1;

    for(int j = 0;j<N;++j)
    {
        getchar();
        pre = H;
        char c;
        string code;
        scanf("%c",&c);
        cin>>code;
        int size = code.size();
        for(int i = 0;i<size;++i)
        {
            // 左子树
            if(code[i]=='0')
            {
                if(pre->left==nullptr)
                {
                    pre->left = new TreeNode();
                    counter+=1;
                }
                if(pre->weight!=0)
                {
                    flag = false;
                }
                pre = pre->left;
            }
                // 右子树
            else if(code[i]=='1')
            {
                if(pre->right==nullptr)
                {
                    pre->right = new TreeNode();
                    counter+=1;
                }
                if(pre->weight!=0)
                {
                    flag = false;
                }
                pre = pre->right;
            }
        }
        if(pre->left||pre->right)
        {
            flag = false;
        }
        pre->weight = hashMap[c];
    }
    if(counter!=2*N-1||!flag||WPL(H,0)!=codeLength)
    {
        return false;
    }
    return true;
}

int main()
{
    vector<HuffmanTree>heap{new TreeNode()};

    // 初始化最小堆
    int N = InitMinHeap(heap);

    // 初始化Huffman树
    HuffmanTree H = InitHuffmanTree(heap);

    // 计算WPL值
    int codeLength = WPL(H,0);
    
    // 检查
    int M;
    scanf("%d",&M);
    for(int i = 0;i<M;++i)
    {
        if(check(N,codeLength))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}
