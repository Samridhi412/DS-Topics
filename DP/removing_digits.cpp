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
	vector<int> dp(n+1);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int temp=i;
		int minsteps=INT_MAX;
		while(temp){
			int di=temp%10;
			temp/=10;
			if(di==0)continue;
			minsteps=min(minsteps,1+dp[i-di]);
		}
		dp[i]=minsteps;
	}
	cout<<dp[n];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}