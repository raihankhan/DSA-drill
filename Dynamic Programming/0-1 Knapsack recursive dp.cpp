#include<bits/stdc++.h>
using namespace std;
int dp[1007][1007];

int knapsack(int v[],int w[],int W,int i)
{
    if(i<0) return 0;
    if(dp[W][i]!=-1) return dp[W][i];

    if(w[i]>W) return dp[W][i]=knapsack(v,w,W,i-1);

    return dp[W][i]= max( knapsack(v,w,W,i-1) , v[i]+knapsack(v,w,W-w[i],i-1) );
}

int main()
{
    int n,W;                            // number of items, weight capacity
    int values[1007],weights[1007];

    cin >> n >> W ;

    for(int i=0;i<n;i++)
        cin >> values[i];
    for(int i=0;i<n;i++)
        cin >> weights[i];

    memset(dp,-1,sizeof(dp));
    cout << knapsack(values,weights,W,n-1) << endl;

    return 0;
}
