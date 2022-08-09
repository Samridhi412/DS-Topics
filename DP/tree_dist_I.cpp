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
vector<int> tree[200005];
int depth[200005];
int ans[200005];
void find_depth(int src){
	int src_depth=0;
	for(int child:tree[src]){
		find_depth(child);
		src_depth=max(src_depth,1+depth[child]);
	}
	depth[src]=src_depth;
}
void tree_dist(int src,int par_ans=-1){
	vector<int> prefix,suffix;
	for(int child:tree[src]){
		prefix.push_back(depth[child]);
		suffix.push_back(depth[child]);
	}
	for(int i=1;i<prefix.size();i++){
		prefix[i]=max(prefix[i-1],prefix[i]);
	}
	
	for(int i=suffix.size()-2;i>=0;i--){
		suffix[i]=max(suffix[i+1],suffix[i]);
	}
	int c_no=0;
	for(int child:tree[src]){
		int op1=(c_no==0)?INT_MIN:prefix[c_no-1];
		int op2=(c_no==suffix.size()-1)>INT_MIN:suffix[c_no+1];
		int partial=1+max(par_ans,max(op1,op2));
		tree_dist(child,partial);
		c_no++;
	}
	ans[src]=1+max(par_ans,(prefix.empty()?-1:prefix.back()));
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	for(int i=2;i<=n;i++){
		int u,v;
		cin>>u>>v;
		tree[u].push_back(v);
	}
	find_depth(1);
	tree_dist(src);
	return 0;
}