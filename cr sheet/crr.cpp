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
int find_path(vector<vector<char>>& labyrinth,int u,int v,vector<vector<bool>> visit,string path,int n,int m,string& final){
	if(u<0||u>=n||v<0||v>=m||visit[u][v]||labyrinth[u][v]=='#'){
		return INT_MAX;
	}
	if(labyrinth[u][v]=='B'){
		if(final.size()>path.size()||final.size()==0)final=path;
		return 0;
	}
	visit[u][v]=true;
	int left=find_path(labyrinth,u,v-1,visit,path+"L",n,m,final);
	int right=find_path(labyrinth,u,v+1,visit,path+"R",n,m,final);
	int up=find_path(labyrinth,u-1,v,visit,path+"U",n,m,final);
	int down=find_path(labyrinth,u+1,v,visit,path+"D",n,m,final);
	visit[u][v]=false;
	return 1+min(left,min(right,min(up,down)));
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<char>> labyrinth(n,vector<char>(m));
	int sx,sy;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>labyrinth[i][j];
			if(labyrinth[i][j]=='A'){
				sx=i;
				sy=j;
			}
		}
	}
	// cout<<sx<<" "<<sy<<endl;
	vector<vector<bool>> visit(n,vector<bool>(m,false));
	string path,final;
	// int dist=0;
	int ans=find_path(labyrinth,sx,sy,visit,path,n,m,final);
	if(ans!=INT_MAX){
		cout<<"YES"<<endl;
		cout<<ans<<endl;
		cout<<final<<endl;
		cout<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}