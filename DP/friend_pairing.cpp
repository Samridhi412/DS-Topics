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
	int dp[n+1];
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-1]+(i-1)*dp[i-2];
	}
	cout<<dp[n];
	return 0;
}