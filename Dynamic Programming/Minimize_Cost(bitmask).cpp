///http://www.shafaetsplanet.com/?p=1357
#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int dp[(1<<15)+7];
int mat[17][17];
int allmasked,n;
bool Is_Set(int mask,int j)
{
    return bool(mask&(1<<j));
}
int Set(int mask,int j)
{
    return mask|(1<<j);
}
lli solve(int mask)
{
    if(mask==allmasked) return 0;
    if(dp[mask]!=-1) return dp[mask];
    int i,j;
    lli price,ans=1e18;
    for(i=0;i<n;i++)
    {
        if(!Is_Set(mask,i))
        {
            price=mat[i][i];
            for(j=0;j<n;j++)
            {
                if(Is_Set(mask,j))
                price+=mat[i][j];
            }
            price+=solve(Set(mask,i));
            ans=min(ans,price);
        }
    }

    return dp[mask]=ans;
}

int main()
{
    int i,j,p;
    cin >> n;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin >> mat[i][j];
    }

    memset(dp,-1,sizeof(dp));
    allmasked=(1<<n)-1;
    cout << solve(0) << endl;

    return 0;

}
