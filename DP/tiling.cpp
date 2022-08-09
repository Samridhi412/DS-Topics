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
int dp[1001][(1<<11)];
void generate(int mask,int i,int next_mask,int n,vector<int>& next_masks){
	if(i==n+1){
		next_masks.push_back(next_mask);
		return;
	}
	if((mask&(1<<i))==1){
		generate(mask,i+1,next_mask,n,next_masks);
	}
	if((mask&(1<<i))&&(mask&(1<<(i+1)))){
		generate(mask,i+2,next_mask,n,next_masks);
	}
	if((mask&(1<<i))==0){
		generate(mask,i+1,next_mask^(1<<i),next_masks);
	}
}
void solve(int col,int mask,int cols,int rows){
	if(col==m+1){
		if(maks==0)return 1;
		return 0;
	}
	else if(dp[col][mask]!=-1)return dp[col][mask];
	int ans=0;
	vector<int> next_masks;
	generate(mask,1,0,n,next_masks);
	for(auto maskss:next_masks){
		ans=(ans+solve(col+1,maskss,cols,rows));
	}
	return dp[col][mask]=ans;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		memset(dp,-1,sizeof dp);
		cout<<solve(1,0,m,n);
	}
	return 0;
}