#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt=0;

bool ratInAMaze(vector<string> maze,int sol[][100], ll i, ll j, ll n, ll m){
	if(i==n && j==m){
		sol[n][m]=1;
		cnt++;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return true;
	}
	if(i>n || j>m){
		return false;
	}
	if(maze[i][j] == 'X'){
		return false;
	}

	sol[i][j] = 1;

	bool rightOne = ratInAMaze(maze, sol, i, j+1, n,m);
	bool downOne = ratInAMaze(maze, sol, i+1, j, n,m);

	// BackTracking
	sol[i][j] = 0;

	if(rightOne || downOne){
		return true;
	}
	return false;
}

int main(){
	ll n=4,m=4; 
	// cin>>n>>m;
	vector<string> maze = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};
	int sol[100][100] = {0};

	bool ans = ratInAMaze(maze, sol, 0, 0, n-1, m-1);

	return 0;
}
