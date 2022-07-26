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
	ll n,m;
	cin>>n>>m;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<vector<int>> dp(n+2,vector<int>(m+2,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1){
				if(arr[i-1]==0||arr[i-1]==j)dp[i][j]=1;
				else dp[i][j]=0;
			}
			else{
			if(arr[i-1]==0||arr[i-1]==j){
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
			}
				else dp[i][j]=0;	
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		ans+=dp[n][i];
	}
	cout<<ans;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}