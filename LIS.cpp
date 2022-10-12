// Longest increasing subsequence 
/*
1 3 2 5 20 6 8 12 
         1 3 2 5 20 6 8 12 

3 2 5 20 6 8 12         1 3 2 5 20 6 8 12 
*/
#include<bits/stdc++.h>
using namespace std;

int lis(int a[],int i,int j,int ans,int n )
{//  cout<<ans<<"\n";
  if(i==0)
  return 1+lis(a,i+1,i,1,n);
  else if(i==n)
  return 0;
  if(a[i]>=a[j])
  return 1+lis(a,i+1,i,ans +1,n);
  else
  {
      return max(ans , max(lis(a,i+1,j,ans,n),1+lis(a,i+1,i,1,n)));
  }
  cout<<ans<<"\n";
  
}
int main()
{
    int a[]  = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout<<lis(a,0,0,0,9);
}