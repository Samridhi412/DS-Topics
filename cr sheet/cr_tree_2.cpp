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
int find_dia(vector<vector<int>>& graph,int root){
	if(graph[root].size()==0){
		return 1;
	}
	
}
void solve(){
	ll n;
	cin>>n;
	vector<vector<int>> graph(n+1);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}
	cout<<find_dia(graph,1);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}