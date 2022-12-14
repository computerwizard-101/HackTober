#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
//void dfs(int u, int par);
// vector<pair<int,int>> a; 
const int mod = 1'000'000'007;
const int N = 1e6, M = N;
//=======================
ll sol = 0;
vi g[N];
int visited[N] = {0};

void dfs2(int i,int a[],int prev,int k,int m)
{   
  if(visited[i]==1)
  return;
  visited[i]=1;
  int current=0;
  if(a[i-1]==1&&prev==1)
  {
    k++;
  }
  else if(a[i-1]==1&&prev==0)
  {
    if(k<=m)
    {
      k=1;
    }
  }
  else
  {
    if(k<=m)
    {
      k=0;
    }
  }

int cnt=0;
  for(int j=0;j<g[i].size();j++)
  { if(visited[g[i][j]]==0)
   { dfs2(g[i][j],a,a[g[i][j]-1],k,m);
   cnt++;
   }

  }
  if(cnt==0)
  { 
    if(k<=m)
    {
      sol++;
    }
  }
  
}
int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int n,m;
  cin>>n>>m;
  int a[n];
  int i,j,k;
 
  fo(i,n-1)
  {
    cin>>j>>k;
    cin>>a[i];
    g[j].push_back(k);
    g[k].push_back(j);
  }
  for(i=1;i<=n;i++)
  if(visited[i]==0)
  dfs2(i,a,a[i],0,m);
  cout<<sol<<"\n";

}


int mpow(int base, int exp)
{
  base %= mod;
  int result = 1;
  while (exp > 0)
  {
    if (exp & 1)
      result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m)
{
  int i, u, v;
  while (m--)
  {
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
}

// void dfs(int u, int par)
// {
//   for (int v : g[u])
//   {
//     if (v == par)
//       continue;
//     dfs(v, u);
//   }
// }
