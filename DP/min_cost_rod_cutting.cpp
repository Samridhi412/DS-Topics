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
int min_cost(vector<int>& arr,int i,int j,vector<vector<int>>& dp){
	if(i>j)return 0;
	else if(dp[i][j]!=-1)return dp[i][j];
	int mini=INT_MAX;
	for(int k=i;k<=j;k++){
		int cost=arr[j+1]-arr[i-1]+min_cost(arr,i,k-1,dp)+min_cost(arr,k+1,j,dp);
		mini=min(mini,cost);
		
	}
	return dp[i][j]=mini;
}
void solve(){
	int len;
	cin>>len;
	ll n;
	cin>>n;
	vector<int> arr(n+2);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	arr[0]=0;
	arr[n+1]=len;
	sort(arr.begin(),arr.end());
	vector<vector<int>> dp2(n+1,vector<int>(n+1,-1));
	min_cost(arr,1,n,dp2);
	vector<vector<int>> dp(n+2,vector<int>(n+2,0));
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			int mini=INT_MAX;
			for(int k=i;k<=j;k++){
				int cost=arr[j+1]-arr[i-1]+dp[i][k-1]+dp[k+1][j];
				mini=min(mini,cost);
				
			}
			 dp[i][j]=mini;
		}
	}
	
	cout<<dp[1][n];
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}