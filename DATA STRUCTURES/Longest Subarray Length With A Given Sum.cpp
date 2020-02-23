#include<bits/stdc++.h>
using namespace std;
//https://www.interviewbit.com/problems/longest-subarray-sum-b
int solve(vector<int> &A, int B) {

    unordered_map<int ,int> mm ;               //Cumulative sum and index hash table

    int sz=A.size(),i,currsum=0,maxlen=-1;

    for(i=0;i<sz;i++)
    {
        currsum+=A[i];

        if(currsum==B)
        maxlen = i+1;                          // if range starts from beginning of the vector

        if(mm.find(currsum) == mm.end())       //if currsum is found for the first time
        mm[currsum]=i;

        if(mm.find(currsum-B)!=mm.end() and maxlen<i-mm[currsum-B])
        maxlen=i-mm[currsum-B];
    }
    return maxlen;
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
