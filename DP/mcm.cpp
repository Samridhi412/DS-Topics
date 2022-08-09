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
int mcm(int i,int j,vector<int>& a,vector<vector<int>>& dp){
	if(i==j)return 0;
	else if(dp[i][j]!=-1)return dp[i][j];
	int mini=INT_MAX;
	for(int k=i;k<j;k++){
		int operations=mcm(i,k,a,dp)+mcm(k+1,j,a,dp)+a[i-1]*a[j]*a[k];
		mini=min(mini,operations);
	}
	return dp[i][j]=mini;
}
void solve(){
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<vector<int>> dp2(n,vector<int>(n,-1));
	mcm(1,n-1,arr,dp2);
	vector<vector<int>> dp(n,vector<int>(n,0));
	for(int i=n-1;i>=1;i--){
		for(int j=i+1;j<n;j++){
			int mini=INT_MAX;
			for(int k=i;k<j;k++){
				mini=min(mini,dp[i][k]+dp[k+1][j]+arr[i-1]*arr[j]*arr[k]);
			}
			dp[i][j]=mini;
		}
	}
	cout<<dp[1][n-1];
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}