/*
Given two strings a and b find
the longest common substring of
these two strings"
*/

#include<bits/stdc++.h>
#define M   1000000007
#define lli long long int
using namespace std;
const int sz=1e5+7;

void test()
{
    string a,b;
    cin >> a >> b ;
    lli A=a.length(),B=b.length();
    if(A>B)
        swap(a,b),swap(A,B);

    lli h1[A+1]={0},h2[A+1]={0},b1=31,b2=29,m1=M,m2=M+2,i,j,k,p1[A+1]={1},p2[A+1]={1};

    for(i=0; i<A; i++)  // hashing of a
    {
        h1[i+1]=(h1[i]+(a[i]-'a'+1)*p1[i])%m1,p1[i+1]=(p1[i]*b1)%m1;
        h2[i+1]=(h2[i]+(a[i]-'a'+1)*p2[i])%m2,p2[i+1]=(p2[i]*b2)%m2;
    }

    lli l=1,r=A,mid;

    while(l<r)
    {
        mid=(l+r)>>1;
        map< pair<lli,lli> , bool>mm;

        for(i=0;i+mid-1<A;i++)
        {
            mm[ { (h1[i+mid]-h1[i]+m1)%m1, (h2[i+mid]-h2[i]+m2)%m2  } ]=1;
        }

        int ha=0,hb=0;
        for(j=0;j<B;j++)
        {
            ha=(ha+p1[j]*(b[j]-'a'+1))%m1;
            hb=(hb+p2[j]*(b[j]-'a'+1))%m2;

            if(j>=mid-1)
            {
                if(ha)
            }
        }
    }




}
void Test()
{
    int T;
    scanf("%d",&T);
    for(int cs=1; cs<=T; cs++)
        test();
}
int main()
{
    test();
    return 0;
}


