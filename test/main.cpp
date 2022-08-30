#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9;
int arr[N];
map<int,int>mp;
int main(){

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){

        cin>>arr[i];
        mp[arr[i]]++;
    }

    while(n--){

        int a,b;
        cin>>a>>b;
        int p;
        for(int i=1;i<=m;i++){

            p=arr[i];
            if((p>a&&p<=b)||(p>b&&p<=a)||p==a||p==b)break;
        }
        if(mp[a]==0&&mp[b]==0){

            printf("ERROR: %d and %d are not found.\n",a,b);
        }
        else if(mp[a]==0||mp[b]==0){

            printf("ERROR: %d is not found.\n",mp[a]==0?a:b);
        }
        else if(p==a||p==b){

            if(p==a)
            printf("%d is an ancestor of %d.\n",p,b);
            else if(p==b)
            printf("%d is an ancestor of %d.\n",p,a);
        }
        else printf("LCA of %d and %d is %d.\n",a,b,p);
    }


    return 0;
}