#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
#define mp make_pair
#define pb push_back
#define endl "\n"
void dfs(vector<vector<char>>& mapp,int x,int y,vector<vector<bool>>& visited,int row,int col){
	if(mapp[x][y]=='#'||visited[x][y]|| x<0||y<0||y>=col||x>=row){
		return;
	}
	visited[x][y]=1;
	dfs(mapp,x+1,y,visited,row,col);
	dfs(mapp,x-1,y,visited,row,col);
	dfs(mapp,x,y+1,visited,row,col);
	dfs(mapp,x,y-1,visited,row,col);
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<char>> mapp(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mapp[i][j];
		}
	}
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mapp[i][j]=='.'&&!visited[i][j]){
				count++;
				dfs(mapp,i,j,visited,n,m);
			}
		}
	}
	cout<< count;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}