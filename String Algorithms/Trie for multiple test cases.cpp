#include<bits/stdc++.h>
#define M   1000000007
#define lli long long int
#define pb push_back
using namespace std;

class node{
public:
    int cnt;  // number of prefixes
    node *edge[5];
};
int getval(char &x)
{
    if(x=='A') return 1;
    if(x=='T') return 2;
    if(x=='C') return 3;
    if(x=='G') return 4;
}
class trie{
public:
   node *root;
   int maxi;
   trie() { root= (node *) calloc(1, sizeof(node)); maxi=0; }

   void insert(string &s)
   {
       node *curr=root;
       for(int i=0;i<s.length();i++)
       {
           int j=getval(s[i]);
           if(curr->edge[j]==nullptr)
            curr->edge[j]=(node *) calloc(1, sizeof(node));

           curr=curr->edge[j];
           curr->cnt++;

           maxi=max(curr->cnt*(i+1),maxi);
       }
   }

    void clean(node *curr)   // clear the trie recursively
    {
        for(int i=1;i<=4;i++)
            if(curr->edge[i]!=nullptr)
            clean(curr->edge[i]);
        delete curr;
    }
   ~trie() { clean(root); }  // destructor

};

void test(int T)
{
    int n,i,j,p;
    string s;
    scanf("%d",&n);
    trie t;
    for(i=0;i<n;i++)
    {
        cin >> s;
        t.insert(s);
    }

    printf("Case %d: %d\n",T,t.maxi);
}
void Test() {   int T;  scanf("%d",&T);   for(int cs=1;cs<=T;cs++)    test(cs); }
int main()
{
    Test();
    //test(1);
    return 0;
}




