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
int distinct_subsequences(string &s,string &t,int i,int j,vector<vector<int>>& dp){
	if(j<0){
		return 1;
	}
	else if(i<0){
		return 0;
	}
	else if(dp[i][j]!=-1)return dp[i][j];
	int nontake=distinct_subsequences(s,t,i-1,j,dp);
	int take=0;
	if(s[i]==t[j])
		{take=distinct_subsequences(s,t,i-1,j-1,dp);}
	return dp[i][j]=take+nontake;
}
void solve(){
	string s,t;
	getline(cin,s);
	getline(cin,t);
	int n=s.size();
	int m=t.size();
	vector<vector<int>> dp2(n,vector<int>(m,-1));
	cout<<distinct_subsequences(s,t,s.size()-1,t.size()-1,dp2)<<endl;
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	// vector<int> prev(m+1,0),curr(m+1,0);
	// prev[0]=curr[0]=1;
	for(int i=0;i<n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int nontake=dp[i-1][j];
			// int nontake=prev[j];
			int take=0;
			if(s[i-1]==t[j-1])
				{
					take=dp[i-1][j-1];
					// take=prev[j-1];
				
				}
			dp[i][j]=take+nontake;
			// curr[j]=take+nontake;
		}
		// prev=curr;
	}
	cout<<dp[n][m];
	// cout<<prev[m];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}