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
bool find_path(vector<vector<char>>& labyrinth,int u,int v,vector<vector<bool>>& visit,string path,int dist,int n,int m){
	if(u<0||u>=m||v<0||v>=n||visit[u][v]||labyrinth[u][v]=='#'){
		return false;
	}
	if(labyrinth[u][v]=='B'){
		return true;
	}
	visit[u][v]=true;
	bool left=find_path(labyrinth,u,v-1,visit,path+"L",dist+1,n,m);
	bool right=find_path(labyrinth,u,v+1,visit,path+"R",dist+1,n,m);
	bool up=find_path(labyrinth,u-1,v,visit,path+"U",dist+1,n,m);
	bool down=find_path(labyrinth,u+1,v,visit,path+"D",dist+1,n,m);
	return left||right||up||down;
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
	vector<vector<bool>> visit(n,vector<bool>(m,false));
	string path;
	int dist=0;
	if(find_path(labyrinth,sx,sy,visit,path,dist,n,m)){
		cout<<"YES"<<endl;
		cout<<dist<<endl;
		cout<<path<<endl;
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