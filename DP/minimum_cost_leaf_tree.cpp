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
pair<ll,ll> min_cost(vector<int>& arr,int st,int end,vector<vector<pair<int,int>>>& dp){
	if(st==end){
		return {arr[st],0};
	}
	else if(dp[st][end]!={-1,-1})return dp[st][end];
	ll mini=1e9;
	ll maxleaf=-1e9;
	for(int i=st;i<end;i++){
		auto left=min_cost(arr,st,i,dp);
		auto right=min_cost(arr,i+1,end,dp);
		maxleaf=max(left.first,right.first);
		ll product=left.second+right.second+left.first*right.first;
		mini=min(mini,product);
	}
	return dp[st][end]={maxleaf,mini};
}
void solve(){
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{-1,-1}));
	min_cost(arr,0,n-1,dp);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}