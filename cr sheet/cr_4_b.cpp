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
// int recursion(int* arr,int n,int sum,vector<vector<int>>& dp){
// 	if(sum==0){
// 		return 1;
// 	}
// 	if(sum<0 || n==0){
// 		return 0;
// 	}
// 	if(dp[n][sum]!=-1)return dp[n][sum];
// 	return dp[n][sum]=recursion(arr+1,n-1,sum-arr[0],dp)+recursion(arr+1,n-1,sum,dp);
	
// }
void solve(){
	cout<<"pp";
	int n,x;
	cin>>n>>x;
	cout<<"llllll";
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"kkk";
	vector<vector<int>> dp(n+1,vector<int>(x+1));
	cout<<"hi";
	dp[0][0]=1;
	cout<<"jjj";
	for(int i=1;i<=x;i++){
		dp[0][i]=0;
	}
	for(int j=1;j<=n;j++){
		dp[j][0]=1;
	}
	cout<<"jjj";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=arr[i-1]){
				dp[i][j]+=dp[i-1][j-arr[i-1]];
			}
		}
	}
	cout<<"hello"<<dp[n+1][x+1];
	// cout<<recursion(arr,n,x,dp);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// ll t;
	// cin>>t;
	// for(int i=0;i<t;i++){
	// 	solve();
	//}
	solve();
	return 0;
}
