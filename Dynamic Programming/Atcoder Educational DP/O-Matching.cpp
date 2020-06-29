#include<bits/stdc++.h>
#define M int(1e9+7)
#define lli long long int
using namespace std;
int com[22][22],dp[22][(1<<21)+2];
int n;
bool Is_Set(int mask,int j)
{
    return mask&(1<<j);
}
int Set(int mask,int j)
{
    return mask|(1<<j);
}
int solve(int man,int woman)
{
    if(man==n) return __builtin_popcount(woman)==n;
    if(dp[man][woman]!=-1) return dp[man][woman];
    int j;
    lli ways=0;
    for(j=0;j<n;j++)
    {
        if(!Is_Set(woman,j) and com[man][j])
            ways+=solve(man+1,Set(woman,j)),ways%=M;
    }
    return dp[man][woman]=ways;
}
int main()
{
    int i,j;

    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&com[i][j]);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(0,0));
    return 0;
}
