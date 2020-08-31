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
#define       scin3(xx,yy,zz)      scanf("%d %d %d",&xx,&yy,&zz)
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
#define       lc(x)                (x<<1)
#define       rc(x)                ((x<<1)|1)
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

int s[3*p5],e[3*p5];
double seg[12*p5],lim=1e9;
veci g[3*p5];
int n,tyme=1;

void process(int id)
{
    seg[id]=seg[lc(id)]+seg[rc(id)];
}
void build(int l,int r,int id)
{
    if(l==r) seg[id]=0;
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,lc(id));
        build(mid+1,r,rc(id));
        process(id);
    }
}
double query(int tl,int tr,int l,int r,int id)
{
    //error(id , tl, tr);
    if(l>tr or r<tl ) return 0;
    if(l<=tl and r>=tr) return seg[id];

    int mid=(tl+tr)>>1;
    double x=query(tl,mid,l,r,lc(id));
    double y=query(mid+1,tr,l,r,rc(id));

    return x+y;
}

void update(int l,int r,int i,double v,int id )
{
    if(i<l and i>r) return;
    if(i==l and l==r)
    {
        seg[id]=v;
        return;
    }

    int mid=(l+r)>>1;
    if(i<=mid)
    update(l,mid,i,v,lc(id));
    else
    update(mid+1,r,i,v,rc(id));
    process(id);
}
void dfs(int u,int par)
{
    s[u]=tyme;

    for(auto v:g[u])
    {
        if(v!=par)
        {
            tyme++;
            dfs(v,u);
        }
    }
    e[u]=tyme;
}

void test(int T)
{
    int i,u,v,q,t,x,y,a,b;
    scin(n);
    rep(i , 0 , n-1)
    {
        scin2(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1,0);
    build(1,n,1);

    //rep(i , 1 , n+1) error(i,s[i],e[i]);

    scin(q);

    while(q--)
    {
        scin3(t,x,y);
        if(t==1)
        {
            update(1,tyme,s[x],log2(1.0*y),1);
        }
        else
        {
            double a=query(1,tyme,s[x],e[x],1);
            double b=query(1,tyme,s[y],e[y],1);

            if((a-b)>=log2(lim))
            cout << doshomik(0) << lim ;
            else
            {
            cout << doshomik(10) <<  pow(2.0,a-b) ;
            }
            pfn;
        }
    }

}
void Test() {   int T;  T=1;  for(int cs=1;cs<=T;cs++)    test(cs); }
int main()
{
    Test();
    return 0;
}

