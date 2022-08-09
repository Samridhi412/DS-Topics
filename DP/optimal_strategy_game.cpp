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
void solve(){
	ll n;
	cin>>n;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int dp[n][n];
	for(int i=0;i<n;i++){
		dp[i][i]=arr[i];
	}
	for(int i=0;i<n-1;i++){
		dp[i][i+1]=max(arr[i],arr[i+1]);
	}
	for(int gap=2;gap<=n;gap++){
		for(int i=0,j=gap;j<n;i++,j++){
			dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
		}
	}
	cout<<dp[0][n-1];
	return 0;
}