//STARS AND BARS PROBLEM  -- (N+K-1)/(N!*(K-1)!) N STARS WITH K-1 BARS
//http://lightoj.com/volume_showproblem.php?problem=1102

#include<bits/stdc++.h>
#define M   1000000007
#define lli long long int
#define pb push_back
using namespace std;
const int sz=2000005;
lli fact[sz];

lli bigmod(lli n,lli k)
{
    lli res=1;
    while(k)
    {
        if(k&1) res=(res*n)%M;
        n=(n*n)%M;
        k>>=1;
    }

    return res;
}
void precal()
{
    fact[0]=1;
    for(lli i=1;i<sz;i++)
    {
        fact[i]=(fact[i-1]*i)%M;
    }

}

void test(int T)
{
    lli n,k,ans;
    scanf("%lld %lld",&n,&k);
    ans= ( fact[n+k-1]*bigmod((fact[n]*fact[k-1])%M , M-2) )%M;
    printf("Case %d: %lld\n",T, ans);
}
void Test() {   int T;  scanf("%d",&T);   for(int cs=1;cs<=T;cs++)    test(cs); }
int main()
{
    precal();
    Test();
    //test(1);
    return 0;
}


