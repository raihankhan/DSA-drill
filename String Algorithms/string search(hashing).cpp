/*
You are given an array of strings. You have to answer a few queries.
Each query contains a string. You need to find if this string can be
found in the array.
Complexity: O(nlogn + q*m)
*/

#include<bits/stdc++.h>
#define M   1000000007
#define lli long long int
using namespace std;
const int sz=1e5+7;

lli p1[sz];

void precal_pow(lli base)
{
    p1[0]=1;
    for(lli i=1;i<=100000;i++)
        p1[i]=(p1[i-1]*base), p1[i]=p1[i]>M?p1[i]%M:p1[i];
}

void test()
{
    int n,i,j;
    string s;
    precal_pow(31);

    cin >> n;

    vector<lli>hash_val(n,0);

    for(i=0;i<n;i++)
    {
        cin >> s;
        for(j=0;j<s.length();j++)
        {
            hash_val[i]=(hash_val[i]+(s[j]-'a'+1)*p1[j])%M;
        }

    }

    sort(hash_val.begin(),hash_val.end());

    int q;
    cin >> q;

    while(q--)
    {
        cin >> s ;
        lli pattern_hash=0;

        for(i=0;i<s.length();i++)
        {
            pattern_hash=(pattern_hash+(s[i]-'a'+1)*p1[i])%M;
        }

        int l=0,r=n,mid;

        while(l<r)
        {
            mid=(l+r)>>1;
            if(hash_val[mid]==pattern_hash)
                break;
            else if(hash_val[mid]>pattern_hash)
                r=mid;
            else l=mid+1;
        }

        if(hash_val[mid]==pattern_hash)
            cout << "Pattern Exists" << endl;
        else cout << "Pattern doesn't Exists" << endl;
    }


}
void Test() {   int T;  scanf("%d",&T);   for(int cs=1;cs<=T;cs++)    test(); }
int main()
{
    test();
    return 0;
}


