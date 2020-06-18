#include<bits/stdc++.h>
using namespace std;
int h[100001];
int dp[100001];
int n,k;
int solve(int stone)
{
    if(stone==n) return 0;
    if(dp[stone]!=-1) return dp[stone];
    int cost=1<<30;
    for(int i=1;i<=k and stone+i<=n;i++)
    cost=min( cost,abs(h[stone]-h[stone+i])+solve(stone+i) );

    return dp[stone]=cost;
}

int main()
{
    int i;
    scanf("%d %d",&n,&k);

    for(i=1; i<=n; i++)
        scanf("%d",&h[i]);

    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(1));


    return 0;
}

