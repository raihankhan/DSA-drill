/*
LOJ 1140
How many zeroes are in the range between m to n
0<=m<=n<=2^32
*/
#include<bits/stdc++.h>
#define M   1000000007
#define lli long long int
#define pb push_back
using namespace std;
const int sz=1e5+7;
vector<int>v;
lli dp[12][12][2][2];

lli solve(int pos,int zero,bool isSmall,bool hasStarted)
{
    if(pos==v.size())  return zero;

    lli &ret= dp[pos][zero][isSmall][hasStarted];
    if(ret!=-1) return ret;
    int limit=isSmall?9:v[pos];
    lli res=0;

    for(int dig=0;dig<=limit;dig++)
    {
        if(dig==0) res+=solve(pos+1,zero + hasStarted ,isSmall|(dig<v[pos]),hasStarted);
        else res+=solve(pos+1,zero, isSmall|(dig<v[pos]),1);
    }

    return ret=res;
}

lli process(lli n)
{
    v.clear();
    while(n)
    {
        v.pb(n%10);
        n/=10;
    }

    reverse(v.begin(),v.end());
    memset(dp,-1,sizeof(dp));
    return solve(0,0,0,0);

}

void test(int T)
{
    lli m,n;
    scanf("%lld %lld",&m,&n);

    lli ans=process(n)-process(m-1);
    if(m==0) ans++;

    printf("Case %d: %lld\n",T,ans);

}
void Test() {   int T;  scanf("%d",&T);   for(int cs=1;cs<=T;cs++)    test(cs); }
int main()
{
    Test();
    return 0;
}


