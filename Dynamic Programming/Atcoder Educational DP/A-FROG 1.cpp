#include<bits/stdc++.h>
using namespace std;
int h[100001];
int dp[100001];
int n;
int solve(int stone)
{
    if(stone+1==n) return dp[stone]=abs(h[stone]-h[stone+1]);
    if(stone+2==n) return dp[stone]=abs(h[stone]-h[stone+2]);
    if(dp[stone]!=-1) return dp[stone];
    return dp[stone]=min(abs(h[stone]-h[stone+1])+solve(stone+1),abs(h[stone]-h[stone+2])+solve(stone+2));
}

int main()
{
    int i;
    scanf("%d",&n);

    for(i=1; i<=n; i++)
        scanf("%d",&h[i]);

    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(1));


    return 0;
}
