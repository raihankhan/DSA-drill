#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/subarray-sum-equals-k
int solve(vector<int>& A, int B)
{

    unordered_map<int,int> mm ;

    int sz=A.size(),i,currsum=0,tot=0;

    for(i=0; i<sz; i++)
    {
        currsum+=A[i];

        if(mm.find(currsum-B)!=mm.end())
            tot+=mm[currsum-B];

        mm[currsum]++;
        if(mm.find(currsum)->first==B)
            tot++;
    }
    return tot;
}
int main()
{
    int n,sum;

    cin >> n ;
    vector<int>v(n);

    for(int i=0;i<n;i++) cin >> v[i];

    cin >> sum ;

    cout << solve(v,sum) << endl;

    return 0;
}
