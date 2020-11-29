/*
Given two strings - a pattern s and a text t,
determine if the pattern appears in the text and if it does,
enumerate all its occurrences in O(|s|+|t|) time.
*/

#include<bits/stdc++.h>
#define M   1000000007
#define lli long long int
using namespace std;
const int sz=1e5+7;

vector<lli> Rabin_Karp(string const& s,string const& t)
{
    lli b1=31,b2=29,m1=M,m2=M+2;
    lli S=s.length(),T=t.length();

    vector<lli>p1(max(S,T),0),p2(max(S,T),0);

    lli i;
    p1[0]=1,p2[0]=1;
    for(i=1;i<p1.size();i++)
    {
        p1[i]=(p1[i-1]*b1)%m1;
        p2[i]=(p2[i-1]*b2)%m2;
    }

    vector<lli>h1(T+1,0),h2(T+1,0);

    for(i=0;i<T;i++)
    {
        h1[i+1]=(h1[i]+(t[i]-'a'+1)*p1[i])%m1;
        h2[i+1]=(h2[i]+(t[i]-'a'+1)*p2[i])%m2;
    }

    lli h_s1=0,h_s2=0;
    for(i=0;i<S;i++)
    {
        h_s1=(h_s1+(s[i]-'a'+1)*p1[i])%m1;
        h_s2=(h_s2+(s[i]-'a'+1)*p2[i])%m2;
    }

    vector<lli>occurances;
    lli curr_h1,curr_h2;
    for(i=0;i+S-1<T;i++)
    {
        curr_h1=(h1[i+S]-h1[i]+m1)%m1;
        curr_h2=(h2[i+S]-h2[i]+m2)%m2;

        if(curr_h1==(p1[i]*h_s1)%m1 and curr_h2==(p2[i]*h_s2)%m2 )  // Double Hash Check
            occurances.push_back(i);  // 0-based index
    }

    return occurances;
}

void test()
{
    string text,pattern;
    cin >> text >> pattern ;

    vector<lli>occurances=Rabin_Karp(pattern,text);

    int i,n;
    n=occurances.size();
    cout << n << endl;
    for(i=0;i<occurances.size();i++)
    printf("%d%c",occurances[i]," \n"[i==n-1]);

}
void Test() {   int T;  scanf("%d",&T);   for(int cs=1;cs<=T;cs++)    test(); }
int main()
{
    test();
    return 0;
}


