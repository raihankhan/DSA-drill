#include<bits/stdc++.h>
#define p5 100005
using namespace std;

int dp[p5][4],a[p5][4];
int n;

int solve(int day,int state)
{
    if(day==n) return a[day][state];
    if(dp[day][state]!=-1) return dp[day][state];
    int cost=a[day][state];
    if(state==1) cost+=max(solve(day+1,2),solve(day+1,3));
    else if(state==2) cost+=max(solve(day+1,1),solve(day+1,3));
    else if(state==3) cost+=max(solve(day+1,1),solve(day+1,2));
    else cost=max( solve(day+1,1), max(solve(day+1,2),solve(day+1,3)) );

    return dp[day][state]=cost;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(0,0));

    return 0;
}
