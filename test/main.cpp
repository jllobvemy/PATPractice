#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <string>
#include <string.h>
#include <thread>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 35;
int n,pre[maxn],post[maxn],in[maxn],_index;
bool flag = false;
void Init()
{
    scanf("%d",&n);
    for(int i =1 ;i <= n;i ++)
        scanf("%d",pre+i);
    for(int i = 1;i <= n;i ++)
        scanf("%d",post+i);
}
void Build_tree(int l1,int r1,int l2,int r2)
{
    if(l1 > r1) return  ;
    if(l1 == r1)
    {
        in[++_index] = pre[l1]; return ;        //中序遍历中的子节点
    }
    int cnt = 0;
    while(post[l2+cnt] != pre[l1+1]) cnt++;
    cnt++;                                     //包括pre[l1+1]本身，所以要+1
    if(l1+cnt == r1)               //只包含当前子节点，并且区间中只有此一个节点
        flag = true;

    Build_tree(l1+1,l1+cnt,l2,l2+cnt-1);         //遍历左子区间
    in[++_index] = pre[l1];                     //中序遍历中的根节点
    Build_tree(l1+cnt+1,r1,l2+cnt,r2-1);        //遍历右子区间
}
int main()
{
    Init();
    Build_tree(1,n,1,n);
    if(flag)
        printf("No\n");
    else
        printf("Yes\n");
    for(int i = 1;i <= n;i ++)
        printf("%d%c",in[i],i==n?'\n':' ');
    return 0;
}