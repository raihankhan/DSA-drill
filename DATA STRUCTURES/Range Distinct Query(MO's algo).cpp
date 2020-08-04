//https://www.spoj.com/problems/DQUERY/
#include<bits/stdc++.h>
#define M   1000000007
#define lli long long int
using namespace std;

class Query
{
public:
    int l,r,id;
    Query(int a,int b,int i)
    {
        l=a,r=b,id=i;
    }
};
int block,unik;
bool cmp(Query a,Query b)
{
    if(a.l/block!=b.l/block)
        return a.l/block < b.l/block;
    return a.r < b.r;
}

int arr[30007];
int freq[1000007];
vector<Query>all;
int ans[200007];

void add(int d){ freq[arr[d]]++; if(freq[arr[d]]==1) unik++; }
void del(int d){ freq[arr[d]]--; if(freq[arr[d]]==0) unik--; }

int main()
{
    int n,i,j,k,p,q,l,r;

    scanf("%d",&n);

    for(i=1;i<=n;i++) scanf("%d",&arr[i]);

    scanf("%d",&q);

    for(i=1;i<=q;i++)
    {
        scanf("%d %d",&l,&r);
        all.push_back(Query(l,r,i));
    }

    block=sqrt(n)+1;
    sort(all.begin(),all.end(),cmp);

    int cur_l=1,cur_r=0;
    for(i=0;i<q;i++)
    {
        l=all[i].l,r=all[i].r;
        while(cur_l>l) { cur_l--; add(cur_l); }
        while(cur_l<l) { cur_l++; del(cur_l-1); }
        while(cur_r>r) { cur_r--; del(cur_r+1); }
        while(cur_r<r) { cur_r++; add(cur_r); }

        ans[all[i].id]=unik;
    }

    for(i=1;i<=q;i++)
        printf("%d\n",ans[i]);

    return 0;
}
