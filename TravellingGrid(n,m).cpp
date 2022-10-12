#include<bits/stdc++.h>
using namespace std;

//recursive approach 
int fun(int x,int y,int n,int m)
{
    if((x == n-1&&y==m)||(y==m-1&&x==n))
    return 1;
    if(x<n)
    {
        if(y<m)
        {
            return fun(x+1,y,n,m)+fun(x,y+1,n,m);
        }
        return fun(x+1,y,n,m);
    }
    return fun(x,y+1,n,m);
}
// recursion using memoisation
long long temp[100][100];
long long fun2(int x,int y,int n,int m)
{
    if((x == n-1&&y==m)||(y==m-1&&x==n))
    {temp[x][y] =1;
    return temp[x][y];
    }
    if(temp[x][y]!=0)
    return temp[x][y];
    if(x<n)
    {
        if(y<m)
        {
            temp[x][y] =fun2(x+1,y,n,m)+fun2(x,y+1,n,m);
            return temp[x][y];
            
        }
        temp[x][y] = fun2(x+1,y,n,m);
    return temp[x][y];
        
    }
    temp[x][y] =fun2(x,y+1,n,m);
    return temp[x][y];
   
}

//dp approach (tabulation)
long long dp(int n ,int m)
{
  long long  dp[100][100];
 //memset(dp,0,sizeof(dp));
 for(int i =1;i<=n;i++)
 {
   dp[i][m] =1;
 }
 for(int i=1;i<=m;i++)
 {
     dp[n][i] =1;

 }
 for(int i = n-1;i>0;i--)
 {
     for(int j =m-1;j>0;j-- )
     {
         dp[i][j] = dp[i+1][j]+dp[i][j+1];
     }
 }
 return dp[1][1];
}
int main()
{
  int n ;
  int m ;
 cin>>n >> m;
 //dp approach 
 cout<<fun2(1,1,n,m);
}