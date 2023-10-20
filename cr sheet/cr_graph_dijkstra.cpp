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
// class edge{
// public:
// 	int src;
// 	int dest;
// 	int weight;
// };
int find_min_dist(int* min_dist,int n,vector<bool>& visit){
	int ans=-1;
	int mini=INT_MAX;
	for(int i=0;i<n;i++){
		if(min_dist[i]<mini&&visit[i]==false){
			ans=i;
		}
	}
	return ans;
}
void dijkstra(vector<vector<pair<int,int>>>& graph,int n){
	vector<bool> visit(n,false);
	int min_dist[n];
	min_dist[0]=0;
	for(int i=1;i<n;i++){
		min_dist[i]=INT_MAX;
	}
	for(int k=0;k<n;k++){
		int min_vertex=find_min_dist(min_dist,n,visit);
		visit[min_vertex]=true;
		for(int i=0;i<graph[min_vertex].size();i++){
			if(!visit[graph[min_vertex][i].first]&&min_dist[graph[min_vertex][i].first]>min_dist[min_vertex]+graph[min_vertex][i].second){
				min_dist[graph[min_vertex][i].first]=min_dist[min_vertex]+graph[min_vertex][i].second;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<i+1<<" "<<min_dist[i]<<endl;
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> graph(n);
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		graph[u-1].push_back({v-1,wt});
	}
	dijkstra(graph,n);
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}