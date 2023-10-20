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
int find_size(int root,map<int,vector<int>>& mp,map<int,int>& ans){
	if(mp.find(root)==mp.end()){
		ans[root]=0;
		return 1;
	}
	int cnt=0;
	for(int i=0;i<mp[root].size();i++){
		int sz=find_size(mp[root][i],mp,ans);
		cnt+=sz;
	}
	ans[root]=cnt;
	return 1+cnt;
}
void solve(){
	int n;
	cin>>n;
	map<int,vector<int>> mp;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		mp[x].push_back(i);
	}
	map<int,int> res;
	int total_nodes=find_size(1,mp,res);
	cout<<total_nodes<<endl;
	for(auto &x:res){
		cout<<x.first<<" "<<x.second<<endl;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}