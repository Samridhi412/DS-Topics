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
void solve(vector<int> tree[],vector<int>& ans,int src){
	int res=0;
	for(auto x:tree[src]){
		solve(tree,ans,x);
		res+=ans[x]+1;
	}
	ans[src]=res;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> tree[n+1];
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		tree[x].push_back(i);
		
	}
	vector<int> ans(n+1);
	solve(tree,ans,1);
	for(auto x:ans){
		cout<<x<<" ";
	}
	return 0;
}