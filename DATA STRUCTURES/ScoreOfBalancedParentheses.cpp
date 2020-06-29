/*  Given a balanced parentheses
    1. () has score 1
    2. AB has score A+B where A and B are balanced parentheses
    3. (A) has score 2*A where A is balanced parentheses
    find the score of a given balanced parentheses
*/
#include<bits/stdc++.h>
using namespace std;
int recur(int lo,int hi,vector<int>closed_index)
{
    if(lo+1==hi) return 1;
    int mid=closed_index[lo];
    if(mid==hi) return recur(lo+1,hi-1,closed_index)<<1;
    return recur(lo,mid,closed_index)+recur(mid+1,hi,closed_index);
}
int cal_score(string s)
{
    int n=s.length();
    stack<int>st;
    vector<int>closed_index(n,0);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') st.push(i);
        else {
            closed_index[st.top()]=i;
            st.pop();
        }
    }

    return recur(0,n-1,closed_index);
}
int main()
{
    string s;
    cin >> s;
    cout << cal_score(s) << endl;
}

