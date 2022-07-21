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
	ll total=n*(n+1)/2;
	cout<<total<<endl;
	if(total%2){cout<<0;return;}
	ll sum1=total/2;
	vector<vector<ll>> dp(n+1,vector<ll>(sum1+1,0));
	dp[0][0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=sum1;j++){
			dp[i][j]=(((j>=i)?dp[i-1][j-i]:0)+dp[i-1][j])%mod;
		}
	}
	ll ans=(dp[n][sum1]*500000004)%mod;
	cout<<ans;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}