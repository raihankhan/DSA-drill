#include<bits/stdc++.h>
///...................................*****.................................................///
///        Author :  Raihan Khan Raka  ( raihankhanraka@gmail.com )                         ///
///                  Department of Computer Science                                         ///
///                  & Engineering                                                          ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

/*....................................Values................................................*/
#define       p5                   100007
#define       p6                   1000007
#define       PI                   acos(-1)
#define       M                    1000000007
#define       inf                  1LL << 62
#define       white                0
#define       gray                 1
#define       black                2
/*....................................Functions.............................................*/
#define       sqr(x)               x*x
#define       sc                   scanf
#define       pf                   printf
#define       pfn                  printf("\n")
#define       scin(x)              sc("%d",&(x))
#define       scin2(xx,zz)         scanf("%d %d",&xx,&zz)
#define       scln(x)              sc("%lld",&(x))
#define       scln2(xx,zz)         scanf("%lld %lld",&xx,&zz)
#define       min3(a,b,c)          min(a,b<c?b:c)
#define       max3(a,b,c)          max(a,b>c?b:c)
#define       all(v)               v.begin(), v.end()
#define       ok                   cout << "ok" << endl
#define       mem(x,y)             memset(x,y,sizeof(x))
#define       clr(a)               a.clear()
#define       READ(f)              freopen(f, "r", stdin)
#define       WRITE(f)             freopen(f, "w", stdout)

/*...................................Data_Types............................................*/
#define       lli                  long long int
#define       ull                  unsigned long long int
#define       pii                  pair < int, int>
#define       pll                  pair < ll, ll>
#define       veci                 vector<int>
#define       vecl                 vector<long long int>
#define       vecp                 vector<  pair<int,int> >
#define       mapstrint            map< string , int >
#define       mapstrstr            map< string , string >
#define       mapint               map< int, int >
#define       uset                 unordered_set
#define       umap                 unordered_map
#define       pq                   priority_queue

#define       pb                   push_back
#define       mp                   make_pair
#define       ff                   first
#define       ss                   second

/*.....................................Loops...............................................*/
#define       rep( i , a , b )     for( i=a ; i<b ; i++)
#define       rev( i , a , b )     for( i=a ; i>=b ; i--)
#define       repx( i ,a,b, x)     for( i=a ; i<b ; i+=x)
#define       doshomik(x)          fixed << setprecision(x)
#define       IOS                  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
//int month[]={31,28,31,30,31,30,31,31,30,31,30,31};

///------------------------------- Mudular functions----------------------------------------
/*
inline lli power(lli x, lli y){ lli temp; if( y == 0) return 1; temp = power(x, y/2); if (y%2 == 0) return temp*temp; else return x*temp*temp; }
inline lli add(lli a, lli b) {a += b; return a >= M ? a - M : a;}
inline lli sub(lli a, lli b) {a -= b; return a < 0 ? a + M : a;}
inline lli mul(lli a, lli b) {return  (a * b) % M;}
lli gcd(lli x,lli y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}
lli bigmod(lli n, lli k )
{
    lli ans=1;
    while(k)
    {
        if(k&1)
            ans=(ans*n)%M;
        k=k>>1;
        n=(n*n)%M;
    }

    return ans;
}
*/
///----------------------------------Graph moves----------------------------------------
/*
int dx4[5] = {1, -1, 0,  0};
int dy4[5] = {0,  0, 1, -1};
int dx8[9] = {0,  0, 1, -1, -1, 1, -1,  1};
int dy8[9] = {-1, 1, 0,  0,  1, 1, -1, -1};
int knightx[9] = {-2, -2, -1, -1,  1, 1, 2,  2};
int knighty[9] = {-1,  1, -2,  2, -2, 2, -1, 1};
bool valid( int r , int c , int x , int y ){ if( x >= 1 && x <= r && y >= 1 && y <= c ) return 1 ; return 0 ; }
*/

using namespace std;

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr  << "[ " << *it << " = " << a << " ] " ; err(++it, args...);  }
///...............................Code Starts Here........................................

int n,m;
veci g[1007];
int level[1007];
int table[10][1007];
void clean()
{
    int i,j;
    rep(i , 1 , n+1) level[i]=0,g[i].clear();
    rep(j , 0 , 10 ) rep(i , 1 , n+1) table[j][i]=0;
}
void table_maker()
{
    int i,j,par;

    rep(j , 1 , 10)
    {
        rep(i , 1 , n+1)
        {
            par=table[j-1][i];
            if(par!=0)
            table[j][i]=table[j-1][par];
        }
    }
}
int walk(int i,int k)
{
    int j;
    rep(j , 0 , 10)
    {
        if(i==0) break;
        if( ((1<<j)&k) > 0)
            i=table[j][i];
    }

    return i;
}
int LCA(int u,int v)
{
    if(level[u]<level[v])
        v=walk(v,level[v]-level[u]);
    if(level[v]<level[u])
        u=walk(u,level[u]-level[v]);
    if(u==v) return u;

    int j;

    rev(j , 9 , 0)
    {
        if(table[j][u]!=table[j][v])
        {

            u=table[j][u];
            v=table[j][v];
        }
    }

    return table[0][u];
}
void bfs(int u)
{
    int par[n+1];
    queue<int>q;
    q.push(u);
    level[u]=0;
    par[u]=0;

    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(auto v:g[u])
        {
            if(v!=par[u])
            {
                par[v]=u;
                table[0][v]=u;
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }

}
void test(int T)
{
    int i,j,u,v,q;
    scin(n);
    rep(u , 1 , n+1)
    {
        scin(m);
        while(m--)
        {
            scin(v);
            g[u].pb(v);
            g[v].pb(u);
        }
    }

    bfs(1);
    table_maker();


    scin(q);
    pf("Case %d:\n",T);
    while(q--)
    {
        scin2(u,v);
        pf("%d\n",LCA(u,v));
    }

    clean();
}
void Test() {   int T;  scanf("%d\n",&T);   for(int cs=1;cs<=T;cs++)    test(cs); }
int main()
{
    Test();
    return 0;
}

