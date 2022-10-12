/*
  Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.
*/
#include<bits/stdc++.h>
using namespace std;

int solve(int amount,vector<int> &coin)
{
   int n= coin.size();
   int dp[n+1][amount+1];
   dp[0][0] = 1;
   //column begin
   for(int i=0;i<=n;i++){
       dp[i][0] = 1;
   }
   //row begin
   for(int j=1;j<=amount;j++)
   {
       dp[0][j] = 0;
   }
   
   //filling dp table
   
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=amount;j++)
       {
           if(j>=coin[i-1])
           {
               dp[i][j] = dp[i][j-coin[i-1]]/*including the current denomination*/ + dp[i-1][j]/*excluding the current denomination*/;

           }
           else
           {
               dp[i][j] = dp[i-1][j]/*no need to include the current denomination*/;
           }
           
       }
   }
   return dp[n][amount];
}
int main()
{
  int n= 3;
  int amount = 4;
  vector<int> coin = {1,2,3};
  cout<<solve(amount,coin)<<endl;

}