#include<bits/stdc++.h>
#define M   1000000007
#define lli long long int
#define pb push_back
using namespace std;
const int sz=2500000;

int trie[sz][5];
int cnt[sz];   // number of prefixes
int nxt,maxi;
void clean()
{
    memset(trie,0,sizeof(trie));
    memset(cnt,0,sizeof(cnt));
    nxt=0;
    maxi=0;
}
int getval(char &x)
{
    if(x=='A') return 1;
    if(x=='T') return 2;
    if(x=='C') return 3;
    if(x=='G') return 4;
}
void insert(string &s)
{
    int v=0;
    for(int i=0;i<s.length();i++)
    {
        int c=getval(s[i]);
        if(trie[v][c]==0)
        {
            trie[v][c]=++nxt;
        }

        v=trie[v][c];
        cnt[v]++;
        maxi=max(maxi,cnt[v]*(i+1));
    }
}
void test(int T)
{
    int n,i,j,p;
    string s;
    scanf("%d",&n);
    clean();
    for(i=0;i<n;i++)
    {
        cin >> s;
        insert(s);
    }

    printf("Case %d: %d\n",T,maxi);
}
void Test() {   int T;  scanf("%d",&T);   for(int cs=1;cs<=T;cs++)    test(cs); }
int main()
{
    Test();
    //test(1);
    return 0;
}



