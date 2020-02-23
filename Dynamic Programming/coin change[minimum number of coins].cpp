#include<bits/stdc++.h>
using namespace std;

//   https://leetcode.com/problems/coin-change/

int coinChange(vector<int>& coins, int amount)
{

    int mini[amount+1],i,j;

    mini[0]=0;          // base solution
    for(i=1; i<=amount; i++)
    {
        mini[i]=amount+1;   // infinite
        for(j=0; j<coins.size(); j++)
        {
            if(coins[j]<=i and mini[i-coins[j]]+1 < mini[i] )
                mini[i]=mini[i-coins[j]]+1;
        }
    }

    if(mini[amount]>amount)
        return -1;
    else return mini[amount];

}

int main()
{
    vector<int>coins;
    int i,p,amount,n;

    cin >> n >> amount ; // number of coins and amount

    for(i=0;i<n;i++)
    {
        cin >> p;
        coins.push_back(p);
    }

    cout << coinChange(coins,amount) << endl;
    return 0;
}
