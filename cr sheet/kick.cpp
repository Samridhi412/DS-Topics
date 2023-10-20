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
bool isSafe(ll i,ll j,vector<vector<char>>& grid,
            vector<vector<bool>>& visit)
int n=grid.size();
int m=grid[0].size();
{     if(i<1||j<1||i>=n||j>=m||grid[i][j]=='#'||visit[i][j])return false;
 
    return false;
}
bool check(vector<vector<char>>& grid,
                  vector<pair<int,int>>& path){
	ll u=path[0].first;
	ll v=path[0].second;
	ll x=path[v-1].first;
	ll y=path[v-1].second;
	if(x-1==u&&y==v||x+1==u&&y==v||x==u&&y-1==v||x==u&&y+1==v)return true;
	return false;
}
string final="";
bool hamCycleUtil(vector<vector<char>>& grid,
                  vector<pair<int,int>>& path,ll v,vector<vector<bool>>& visit,ll i,ll j)
{ 
	
    if (path.size() == v)
    {
        if (check(grid,path))
            return true;
        else
            return false;
    }
    int dx={0,0,1,-1};
    int dy={-1,1,0,0};
    string arr={"W","E","S","N"};
    for (int k = 0; k < 4; k++)
    { int w=i+dx[k];
    	int z=j+dy[k];
    	
    	
        if (isSafe(w,z,grid,visit))
        {
            path.push_back({w,z});
            visit[w][z]=1;
            final+=arr;
            if (hamCycleUtil (grid, path,v,visit,w,z) == true)
                return true;
            path.pop_back();
            visit[w][z]=0;
        }
    }
    return false;
}
 
void hamCycle(vector<vector<char>>& grid,ll V,vector<vector<bool>>& visit)
{
    vector<pair<int,int>> path;
    path.push_back({1,1});
    visit[1][1]=true;
    if (hamCycleUtil(grid, path,V,visit,1,1) == false )
    {
    	cout<<"IMPOSSIBLE"<<endl;
        return;
    }
 
    cout<<final<<endl;
    return;
}
void solve(){
	ll r,c;
	cin>>r>>c;
	ll V=0;
	vector<vector<char>> grid(2*r+1,vector<char>(2*c+1));
	// vector<char> blocks(r+1,vector<char>(c));
	for(ll i=1;i<=r;i++){
		for(ll j=1;j<=c;j++){
			char ch;
			cin>>ch;
			//A2i−1,2j−1,A2i−1,2j,A2i,2j−1, and A2i,2j 
			ll x=2*i-1;
			ll y=2*j-1;
			ll x1=2*i;
			ll y2=2*j;
			grid[x][y]=ch;
			grid[x][y2]=ch;
			grid[x1][y]=ch;
			grid[x1][y2]=ch;
			if(ch=='*'){
				V+=4;
			}
		}
	}
     vector<vector<bool>> visit(2*r+1,vector<bool>(2*c+1,false));
	 hamCycle(grid,V,visit);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}