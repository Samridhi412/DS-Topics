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
ll buy_sell(vector<int>& arr,int n,int ind,int isbuy,vector<vector<int>>& dp){
	if(ind==n){
		return 0;
	}
	else if(dp[ind][isbuy]!=-1)return dp[ind][isbuy];
	ll nontake=buy_sell(arr,n,ind+1,isbuy);
	ll take=0;
	if(isbuy){
		take=buy_sell(arr,n,ind+1,0)-arr[ind];
	}
	else{
		take=buy_sell(arr,n,ind+1,1)+arr[ind];
	}
	return dp[ind][isbuy]=max(nontake,take);
}
ll small_code(vector<int>& arr,int n){
	ll aheadbuy=0,aheadnotbuy=0;
	ll currbuy,currnotbuy;
	for(int i=n-1;i>=0;i--){
		currbuy=max(-arr[i]+aheadnotbuy,aheadbuy);
		currnotbuy=max(+arr[i]+aheadbuy,aheadnotbuy);
		aheadbuy=currbuy;
		aheadnotbuy=currnotbuy;
	}
	cout<<aheadbuy;
}
void solve(){
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	vector<vector<int>> dpp(n,vector<int>(2,-1));
	buy_sell(arr,n,0,1,dpp);
	vector<vector<int>> dp(n+1,vector<int>(2,0));
	dp[n][0]=dp[n][1]=0;
	vector<int> prev(2,0),curr(2,0);
	prev[0]=prev[1]=0;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=1;j++){
				ll nontake=dp[i+1][j];
			    // nontake=prev[j]; 
				ll take=0;
				if(j){
					take=dp[i+1][0]-arr[i];
					// take=prev[0]-arr[i];
				}
				else{
					take=dp[i+1][1]+arr[i];
					// take=prev[1]+arr[i];
				}
				dp[i][j]=max(nontake,take);
				// curr[j]=max(nontake,take);
		}
		// prev=curr;
	}
	cout<<dp[0][1];
	// cout<<prev[1];
	
	
	
	cout<<small_code(arr,n)<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}