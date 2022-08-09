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
	int n;
	cin>>n;
	vector<int> costs(n);
	for(int i=0;i<n;i++){
		cin>>costs[i];
	}
	vector<int> dp(n+1);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int answer=-1e5;
		for(int j=1;j<=i;j++){
			answer=max(answer,costs[j-1]+dp[i-j]);
		}
		dp[i]=answer;
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