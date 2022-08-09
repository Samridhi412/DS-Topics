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
ll dp[11][(1<<11)];
ll hamiltonian(vector<vector<int>>& graph,int start,int mask,int n){
	int cnt=__builtin_popcount();
	if(cnt==n){
		return 1;
	}
	// you are at last city but not all cities visited
	else if(start==n-1){
		return 0;
	}
	else if(dp[start][mask]!=-1)return dp[start][mask];
	ll res=0;
	for(int j=0;j<n;j++){
		if(j!=start&&!(mask&(1<<j))&&graph[start][j]!=0){
			res+=hamiltonian(graph,j,mask^(1<<j),n);
		}
	}
	return dp[start][mask]=res;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll cities,edges;
	cin>>cities>>edges;
	memset(dp,-1,sizeof dp);
	vector<vector<int>> graph(cities,vector<int>(cities,0));
	for(int i=0;i<edges;i++){
		int u,v,dist;
		cin>>u>>v>>dist;
		graph[u][v]=dist;
	}
	hamiltonian(graph,0,1,cities);
	return 0;
}