//BURNSIDE LEMMA- Necklace Problem
//http://lightoj.com/volume_showproblem.php?problem=1419

#include<bits/stdc++.h>
#define M   1000000007
#define lli long long int
#define pb push_back
using namespace std;
const int sz=1e5+7;
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
void test(int T)
{
    lli n,k,ans=0;
    scanf("%lld %lld",&n,&k);
    for(lli i=0;i<n;i++)
    {
        ans+=bigmod(k,__gcd(i,n));
        ans%=M;
    }

    ans*=bigmod(n,M-2);
    ans%=M;

    printf("Case %d: %lld\n",T,ans);
}
void Test() {   int T;  scanf("%d",&T);   for(int cs=1;cs<=T;cs++)    test(cs); }
int main()
{
    Test();
    //test(1);
    return 0;
}



