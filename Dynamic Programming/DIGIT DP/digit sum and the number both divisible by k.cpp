/*
LOJ 1068
How many integers are divisible by k and their digit sum is also divisible by k
between and inclusive range a to b , 1<=a<=b<=10^9
*/

#include<bits/stdc++.h>
#define M   1000000007
#define lli long long int
#define pb push_back
using namespace std;
const int sz=1e5+7;
vector<int>v;
int dp[11][2][91][91];
int k;

int solve(int pos,int isSmall,int sum,int rem)
{
    if(pos==v.size()) return (sum%k==0 and rem==0);
    int  &ret = dp[pos][isSmall][sum][rem];
    if(ret!=-1) return ret;
    int limit=isSmall?9:v[pos];
    int dig,res=0;

    for(dig=0;dig<=limit;dig++)
    {
        res+=solve(pos+1,isSmall|(dig<v[pos]),sum+dig,((rem*10)+dig)%k);
    }

    return ret=res;
}

int process(int n)
{
    if(k>81) return 0;
    v.clear();
    while(n)
    {
        v.pb(n%10);
        n=n/10;
    }

    reverse(v.begin(),v.end());

    memset(dp,-1,sizeof(dp));
    return solve(0,0,0,0);

}
void test(int T)
{
    int a,b;
    scanf("%d %d %d",&a,&b,&k);
    printf("Case %d: %d\n",T,process(b)-process(a-1));
}
void Test() {   int T;  scanf("%d",&T);   for(int cs=1;cs<=T;cs++)    test(cs); }
int main()
{
    Test();
    //test(1);
    return 0;
}



