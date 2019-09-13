
/* This is a very basic implementation of Depth First search. This Algorithm only traverses an undirected Graph . */

#include<bits/stdc++.h>
///...................................*****.................................................///
///                  Raihan Khan Raka                                                       ///
///                  Department of Computer Science                                         ///
///                  & Engineering                                                          ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#define       PI                   acos(-1)
#define       min3(a,b,c)          min(a,min(b,c))
#define       max3(a,b,c)          max(a,max(b,c))
#define       READ(f)              freopen(f, "r", stdin)
#define       WRITE(f)             freopen(f, "w", stdout)
#define       lli                  long long int
#define       ull                  unsigned long long int
#define       pii                  pair < int, int>
#define       pll                  pair < ll, ll>
#define       sc                   scanf
#define       scin(x)              sc("%d",&(x))
#define       scln(x)              sc("%lld",&(x))
#define       pf                   printf
#define       veci                 vector<int>
#define       vecl                 vector<long long int>
#define       vecp                 vector<  pair<int,int> >
#define       pb                   push_back
#define       inf                  1<<30
#define       mp                   make_pair
#define       ss                   stringstream
#define       all(v)               v.begin(), v.end()
#define       mem(x,y)             memset(x,y,sizeof(x))
#define       FastRead             ios_base::sync_with_stdio(0);cin.tie(0)
#define       M                    1000000007
#define       rep( i , a , b )     for( i=a ; i<b ; i++)
#define       rev( i , a , b )     for( i=a ; i>b ; i--)
//int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
//long power(long int x, long int y){ int temp; if( y == 0) return 1; temp = power(x, y/2); if (y%2 == 0) return temp*temp; else return x*temp*temp; }
/*lli gcd(lli x,lli y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}*/
/*
int dx[5] = {1, -1, 0, 0 };
int dy[5] = {0, 0, 1, -1};
*/
using namespace std;

veci graph[10007];
bool visited[10007];
int n , e;

void dfs( int src )
{
    int i;
    visited[src] = true;

    rep( i , 0 , graph[src].size()  )
    {
        if( visited[ graph[src][i] ] == false)
        {
            dfs( graph[src][i] );
        }
    }
}

void edge( int u, int v)
{
    graph[u] . pb(v);
    graph[v] . pb(u);
}

void initialize()
{
    int i;
    mem( visited , false) ;
    rep( i , 0 , 10001) graph[i].clear();
}

int main()
{
    int u,v,i;

    scin(n);
    scin(e);

    initialize();

    rep( i , 0 , e)
    {
        scin(u);
        scin(v);

        edge(u,v);
    }

    dfs(0);



    return 0;
}
