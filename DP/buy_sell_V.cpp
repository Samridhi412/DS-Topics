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
int buy_sell(vector<int>& arr,int n,int ind,int isbuy,vector<vector<int>>& dp){
	if(ind>=n)return 0;
	else if(dp[ind][isbuy]!=-1)return dp[ind][isbuy];
	ll profit=-1e9;
	if(isbuy){
		profit=max(-arr[ind]+buy_sell(arr,n,ind+1,0,dp),buy_sell(arr,n,ind+1,1,dp));
	}
	else{
		profit=max(arr[ind]+buy_sell(arr,n,ind+2,1,dp),buy_sell(arr,n,ind+1,0,dp));
	}
	return dp[ind][isbuy]=profit;
}
void solve(){
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<vector<int>> dpp(n,vector<int>(2,-1));
	cout<<buy_sell(arr,n,0,1,dpp)<<endl;;
	vector<vector<int>> dp(n+2,vector<int>(2,0));
	vector<int> next2(2,0),next1(2,0),curr(2,0);
	for(int i=n-1;i>=0;i--){
		// dp[i][0]=max(arr[i]+dp[i+2][1],dp[i+1][0]);
		// dp[i][1]=max(-arr[i]+dp[i+1][0],dp[i+1][1]);
		curr[0]=max(arr[i]+next2[1],next1[0]);
		curr[1]=max(-arr[i]+next1[0],next1[1]);
		
		next2=next1;
		next1=curr;
	}
	// cout<<dp[0][1];
	cout<<next1[1];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}