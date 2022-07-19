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
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int sum;
	cin>>sum;
	vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			dp[i][j]=dp[i-1][j];
			// cout<<arr[i-1]<<endl;
			if(arr[i-1]<=j){
				dp[i][j]+=dp[i][j-arr[i-1]];
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[n][sum];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}