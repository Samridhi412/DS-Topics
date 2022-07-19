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
	ll n,x;
	cin>>n>>x;
	vector<int> prices(n);
	vector<int> pages(n);
	for(int i=0;i<n;i++){
		cin>>prices[i];
	}
	for(int i=0;i<n;i++){
		cin>>pages[i];
	}
	
	vector<vector<int>> dp(n,vector<int>(x+1,0));
	for(int i=0;i<=x;i++){
		if(prices[0]<=i){
			dp[0][i]=pages[0];
		}
	}
	// if(prices[0]<=x)dp[0][prices[0]]=pages[0];
	for(int i=1;i<n;i++){
		for(int j=1;j<=x;j++){
			dp[i][j]=dp[i-1][j];
			if(prices[i]<=j){
				dp[i][j]=max(dp[i][j],pages[i]+dp[i-1][j-prices[i]]);
			}
		}
	}
	cout<<dp[n-1][x];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}