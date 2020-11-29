/*
COUNT THE NUMBER OF INTERGERS WITHIN RANGE A TO B
WHOSE DIGIT SUM EQUALS TO X
A,B <= 10^9 AND X<=10^5
*/

#include<bits/stdc++.h>
#define M   1000000007
#define lli long long int
#define pb push_back
using namespace std;
const int sz=1e5+7;
int X;
vector<int>v;
int dp[11][2][91];  // Maximum 10 digits, previous digit from left is already small or not, max_digit_sum
int solve(int pos,int isSmall,int sum)
{
    if(pos==v.size())
    {
        return sum==X;
    }
    int &ret= dp[pos][isSmall][sum];
    if(ret!=-1) return ret;

    int limit=isSmall?9:v[pos];
    int res=0;
    for(int dig=0;dig<=limit;dig++)
    {
        res+=solve(pos+1,isSmall|(dig<v[pos]),sum+dig);
    }

    return ret=res;
}
int process(int n)
{
    v.clear();
    while(n)
    {
        v.pb(n%10);
        n/=10;
    }
    reverse(v.begin(),v.end());
    memset(dp,-1,sizeof(dp));
    return solve(0,0,0);
}
void test()
{
    int A,B;
    cin >> A >> B >> X ;
    cout << process(B)-process(A-1) << endl;

}
void Test() {   int T;  scanf("%d",&T);   for(int cs=1;cs<=T;cs++)    test(); }
int main()
{
    test();
    return 0;
}


