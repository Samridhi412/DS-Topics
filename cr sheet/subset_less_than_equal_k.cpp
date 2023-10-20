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
int recur(int* arr,int n,int sum,vector<vector<int>>& dp,int ind){
	if(ind==n){
		return 1;
	}
	if(dp[n][sum]!=-1)return dp[n][sum];
	if(arr[ind]<=sum){
		dp[n][sum]= recur(arr,n,sum,dp,ind+1)+recur(arr,n,sum-arr[ind],dp,ind+1);
	}
	else{
		dp[n][sum]=recur(arr,n,sum,dp,ind+1);
	}
	return dp[n][sum];
}
void solve(){
	int n,x;
	cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
	dp[0][0]=1;
	for(int i=1;i<=x;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=x;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=ar[i-1]){
				dp[i][j]+=dp[i-1][j-arr[i-1]];
			}
		}
	}
	int sum=0;
	for(int i=0;i<=x;i++){
		sum+=dp[n][i];
	}
	cout<<sum<<endl;
	// cout<<recur(arr,n,x,dp,0);
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	// solve();
	return 0;
}