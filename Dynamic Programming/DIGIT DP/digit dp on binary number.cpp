/*
LOJ 1032
If a bit of a number is 1 and its next bit is also 1 then we can say that the number has a 1 adjacent bit.
And you have to find out how many times this scenario occurs for all numbers up to N
*/

#include<bits/stdc++.h>
#define M   1000000007
#define lli long long int
#define pb push_back
using namespace std;
const int sz=1e5+7;
lli dp[33][2][2][33]; // pos=32 , isSmall=2, lastDig=2 , total condition match
vector<int>v;

lli solve(int pos,int isSmall,int lastDig,int total)
{
    if(pos==v.size()) return total;
    lli &ret = dp[pos][isSmall][lastDig][total];
    if(ret!=-1) return ret;
    lli res=0;
    int limit;
    if(!isSmall) limit=v[pos];
    else limit=1;

    for(int dig=0;dig<=limit;dig++)
    {
        int New_isSmall=isSmall|(dig<v[pos]);
        res+=solve(pos+1 , New_isSmall , dig , total + (lastDig==dig and dig==1) );
    }

    return ret=res;
}

lli process(int n)
{
    v.clear();
    int p;
    while(n>0)
    {
        p=n%2;
        v.pb(p);
        n/=2;
    }

    reverse(v.begin(),v.end());
    memset(dp,-1,sizeof(dp));
    return solve(0,0,0,0);

}

void test(int T)
{
    int n;
    scanf("%d",&n);
    printf("Case %d: %lld\n",T,process(n));
}
void Test() {   int T;  scanf("%d",&T);   for(int cs=1;cs<=T;cs++)    test(cs); }
int main()
{
    Test();
    //test(1);
    return 0;
}



