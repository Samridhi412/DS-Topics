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
long buy_I(int* values,int n){
	int mini=values[0];
	int profit=0;
	for(int i=1;i<n;i++){
		int cost=values[i]-mini;
		profit=max(profit,cost);
		mini=min(mini,values[i]);
	}
	return profit;
}
long buy_II(long* values,int n,int ind,bool buy,vector<vector<long>>& dp){
	if(ind==n){
		return 0;
	}
	if(dp[ind][buy]!=-1)return dp[ind][buy];
	if(buy){
		return dp[ind][buy]=max(-values[ind]+buy_II(values,n,ind+1,0,dp),buy_II(values,n,ind+1,1,dp));
	}
	return dp[ind][buy]=max(values[ind]+buy_II(values,n,ind+1,1,dp),buy_II(values,n,ind+1,0,dp));
}
void solve(){
	int n;
	cin>>n;
	long values[n];
	for(int i=0;i<n;i++){
		cin>>values[i];
	}
	// cout<<buy_I(values,n);
	vector<vector<long>> dp(n+1,vector<long>(2,-1));
	cout<<buy_II(values,n,0,1,dp);
	// vector<vector<long>> dpp(n+1,vector<long>(2,0));
	// vector<long> prev(2,0),curr(2,0);
	long prevbuy=0,prevnotbuy=0;
	long int currbuy,currnotbuy;
	// dpp[n][0]=0;
	// dpp[n][1]=0;
	// prev[0]=0;
	// prev[1]=0;
	for(int i=n-1;i>=0;i--){
	   currnotbuy=max(values[i]+prevbuy,prevnotbuy);
		currbuy=max(-values[i]+prevnotbuy,prevbuy);
		prevbuy=currbuy;
		prevnotbuy=currnotbuy;
	}
	cout<< prevbuy;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}