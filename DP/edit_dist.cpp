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
	string s,t;
	cin>>s>>t;
	int n=s.size();
	int m=t.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=m;i++){
		dp[0][i]=i;
	}
	for(int j=1;j<=n;j++){
		dp[j][0]=j;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
			}
		}
	}
	cout<<dp[n][m];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}