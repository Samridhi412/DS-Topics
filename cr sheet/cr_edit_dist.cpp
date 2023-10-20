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
int edit_dist(string s1,string s2,int i,int j,vector<vector<int>>& dp){
	if(i<0&&j<0){
		return 0;
	}
	if(i<0){
		return j+1;
	}
	if(j<0){
		return i+1;
	}
	if(dp[i][j]!=-1)return dp[i][j];
	if(s1[i]==s2[j]){
		return dp[i][j]=edit_dist(s1,s2,i-1,j-1,dp);
	}
	return dp[i][j]=1+min(edit_dist(s1,s2,i-1,j-1,dp),min(edit_dist(s1,s2,i,j-1,dp),edit_dist(s1,s2,i-1,j,dp)));
}
void solve(){
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.size();
	int m=s2.size();
	vector<vector<int>> dp(n,vector<int>(m,-1));
	cout<<edit_dist(s1,s2,n-1,m-1,dp);
	vector<vector<int>> dp2(n+1,vector<int>(m+1,0));
	vector<int> prev(m+1,0),curr(m+1,0);
	
	// dp2[0][0]=0;
	// for(int i=1;i<=m;i++){
	// 	dp2[0][i]=i;
	// }
	// for(int i=1;i<=n;i++){
	// 	dp2[i][0]=i;
	// }
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		if(s1[i-1]==s2[j-1]){
	// 			dp2[i][j]=dp2[i-1][j-1];
	// 		}
	// 		else{
	// 			dp2[i][j]=1+min(dp2[i-1][j-1],min(dp2[i][j-1],dp2[i-1][j]));
	// 		}
	// 	}
	// }
	// cout<<dp2[n][m];
	for(int i=1;i<=m;i++){
		prev[i]=i;
	}
	for(int i=1;i<=n;i++){
		curr[0]=i;
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				curr[j]=prev[j-1];
			}
			else{
				curr[j]=1+min(prev[j-1],min(curr[j-1],prev[j]));
			}
		}
		prev=curr;
	}
	cout<<prev[m];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}