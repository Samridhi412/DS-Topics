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
ll buy_sell(vector<int>& arr,int ind,int n,int cap,int isbuy,vector<vector<vector<int>>>& dp){
	if(cap==0||ind==n)return 0;
	else if(dp[ind][isbuy][cap]!=-1)return dp[ind][isbuy][cap];
	ll profit=-1e9;
	if(isbuy){
		profit=max(-arr[ind]+buy_sell(arr,ind+1,n,cap,0,dp),buy_sell(arr,ind+1,n,cap,1,dp));
	}
	else {
		profit=max(arr[ind]+buy_sell(arr,ind+1,n,cap-1,1,dp),buy_sell(arr,ind+1,n,cap,0,dp));
	}
	return dp[ind][isbuy][cap]=profit;
	
}
ll space_recur(vector<int>& arr,int ind,int n,int id){
	if(ind==n||id==4){
		return 0;
	}
	ll profit=-1e9;
	if(id%2==0){
		profit=max(-arr[ind]+space_recur(arr,ind+1,n,id+1),space_recur(arr,ind+1,n,id));
	}
	else{
		profit=max(+arr[ind]+space_recur(arr,ind+1,n,id+1),space_recur(arr,ind+1,n,id));
	}
	return profit;
}
ll space_optimize(vector<int>& arr,int n){
	vector<vector<int>> dp(n+1,vector<int>(5,0));
	for(int i=n-1;i>=0;i--){
		for(int id=3;id>=0;id--){
			if(id%2==0){
				dp[i][id]=max(-arr[i]+dp[i+1][id+1],dp[i+1][id]);
			}
			else{
				dp[i][id]=max(arr[i]+dp[i+1][id+1],dp[i+1][id]);
			}
		}
	}
	return dp[0][0];
}
void solve(){
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
	// cout<<buy_sell(arr,0,n,2,1,dp);
	for(int i=n-1;i>=0;i--){
		for(int cap=1;cap<3;cap++){
			dp[i][0][cap]=max(arr[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
			dp[i][1][cap]=max(-arr[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
		}
	}
	cout<<dp[0][1][2]<<endl;
	cout<<space_optimize(arr,n);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}