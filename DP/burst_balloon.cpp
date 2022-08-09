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
int burst_ballon(vector<int>& a,int i,int j,vector<vector<int>>& dp){
	if(i>j){
		return 0;
	}
	else if(dp[i][j]!=-1)return dp[i][j];
	int maxi=-1e9;
	for(int ind=i;ind<=j;ind++){
		int cost=a[i-1]*a[ind]*a[j+1]+burst_ballon(a,i,ind-1,dp)+burst_ballon(a,ind+1,j,dp);
		maxi=max(maxi,cost);
	}
	return dp[i][j]=maxi;
}
void solve(){
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	arr.push_back(1);
	arr.insert(arr.begin(),1);
	vector<vector<int>> dpp(n+1,vector<int>(n+1,-1));
	cout<<burst_ballon(arr,1,n,dpp);
	vector<vector<int>> dp(n+2,vector<int>(n+2,0));
	for(int i=n;i>0;i--){
		for(int j=i+1;j<n;j++){
			int maxi=-1e9;
			for(int ind=i;ind<=j;ind++){
				int cost=a[i-1]*a[ind]*a[j+1]+dp[i][ind-1]+dp[ind+1][j];
				maxi=max(maxi,cost);
			}
			 dp[i][j]=maxi;
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