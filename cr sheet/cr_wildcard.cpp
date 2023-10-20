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
int wildcard_matching(string s,string pattern,int i,int j,vector<vector<int>>& dp){
	if(i<0&&j<0){
		return true;
	}
	if(j<0){
		return false;
	}
	if(i<0){
		for(int k=0;k<=j;k++){
			if(pattern[k]!='*'){
				return false;
			}
		}
		return true;
	}
	if(dp[i][j]!=-1)return dp[i][j];
	 if(s[i]==pattern[j]||pattern[j]=='?'){
	 	return dp[i][j]=wildcard_matching(s,pattern,i-1,j-1,dp);
	 }
	 else if(pattern[j]=='*'){
	 	return dp[i][j]=wildcard_matching(s,pattern,i-1,j,dp)||wildcard_matching(s,pattern,i,j-1,dp);
	 }
	 return dp[i][j]=false;
}
void solve(){
	string s,p;
	cin>>s>>p;
	int n=s.size();
	int m=p.size();
	vector<vector<int>> dp(n,vector<int>(m,-1));
	cout<<wildcard_matching(s,p,n-1,m-1,dp)<<endl;
	// vector<vector<bool>> dp2(n+1,vector<bool>(m+1,false));
	vector<bool> prev(m+1,false),curr(m+1,false);
	// dp2[0][0]=true;
	// for(int i=1;i<=n;i++){
	// 	dp2[i][0]=false;
	// }
	// for(int i=1;i<=m;i++){
	// 	bool flag=0;
	// 	for(int k=0;k<i;k++){
	// 		if(p[k]!='*'){
	// 			flag=1;
	// 			break;
	// 		}
	// 	}
	// 	if(flag)dp2[0][i]=false;
	// 	else dp2[0][i]=true;
	// }
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		if(s[i-1]==p[j-1]||p[j-1]=='?'){
	// 		  dp2[i][j]=dp2[i-1][j-1];
	// 		}
	// 		else if(p[j-1]=='*'){
	// 			dp2[i][j]=dp2[i-1][j]||dp2[i][j-1];
	// 		}
	// 	}
	// }
	// cout<<dp2[n][m];
	prev[0]=true;
	for(int i=1;i<=m;i++){
		bool flag=0;
		for(int k=0;k<i;k++){
			if(p[k]!='*'){
				flag=1;
				break;
			}
		}
		if(flag)prev[i]=false;
		else prev[i]=true;
	}
	for(int i=1;i<=n;i++){
		curr[0]=false;
		for(int j=1;j<=m;j++){
			if(s[i-1]==p[j-1]||p[j-1]=='?'){
			  curr[j]=prev[j-1];
			}
			else if(p[j-1]=='*'){
				curr[j]=prev[j]||curr[j-1];
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