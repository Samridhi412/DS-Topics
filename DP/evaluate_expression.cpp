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
ll evaluate(string s,int i,int j,bool istrue,vector<vector<vector<int>>>& dp){
	if(i>j)return 0;
	else if(i==j){
		// cout<<s[i]<<endl;
		if(istrue){
			return s[i]=='T'?1:0;
		}
		else{
			return s[i]=='F'?1:0;
		}
		
	}
	else if(dp[i][j][istrue]!=-1)return dp[i][j][istrue];
	ll ways=0;
	for(int k=i+1;k<j;k+=2){
		// cout<<k<<endl;
		int lt=evaluate(s,i,k-1,1,dp);
		int lf=evaluate(s,i,k-1,0,dp);
		int rt=evaluate(s,k+1,j,1,dp);
		int rf=evaluate(s,k+1,j,0,dp);
		// cout<<lt<<" "<<lf<<" "<<rt<<" "<<rf<<endl;
		
		if(s[k]=='|'){
			if(istrue){
				ways=(ways+(lt*rt)%mod+(lt*rf)%mod+(lf*rt)%mod)%mod;;
			}
			else{
				ways=(ways+(lf*rf)%mod)%mod;
			}
		}
		else if(s[k]=='&'){
			if(istrue){
				ways=(ways+(lt*rt)%mod)%mod;
			}
			else{
				ways=(ways+(lf*rf)%mod+(lt*rf)%mod+(lf*rt)%mod)%mod;
			}
		}
		else if(s[k]=='^'){
			if(istrue){
				ways=(ways+(lt*rf)%mod+(lf*rt)%mod)%mod;
			}
			else{
				ways=(ways+(lt*rt)%mod+(lf*rf)%mod)%mod;
			}
		}
		// cout<<ways<<endl;
	}
	return dp[i][j][istrue]=ways%mod;
}
void solve(){
	string s;
	// getline(cin,s);
	cin>>s;
	// cout<<"abcd"<<s<<endl;
	if(s.size()==1){
	  if(s[0]=='T')cout<<1<<endl;
	  else cout<<0;
	}
	int n=s.size();
	// vector<vector<vector<int>>> dp2(n,vector<vector<int>>(n,vector<int>(2,-1)));
	// ll value=evaluate(s,0,n-1,1,dp2);
	// cout<<value;
	// TABULATION //
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,0)));
	for(int i=0;i<n;i+=2){
		dp[i][i][1]=(s[i]=='T')?1:0;
		dp[i][i][0]=(s[i]=='F')?1:0;
	}
	for(int i=n-1;i>=0;i--){
		for(int j=i+1;j<n;j++){
			for(int istrue=0;istrue<=1;istrue++){
				ll ways=0;
			for(int k=i+1;k<j;k+=2){
		int lt=dp[i][k-1][1];
		int lf=dp[i][k-1][0];
		int rt=dp[k+1][j][1];
		int rf=dp[k+1][j][0];
		if(s[k]=='|'){
			if(istrue){
				ways=(ways+(lt*rt)%mod+(lt*rf)%mod+(lf*rt)%mod)%mod;;
			}
			else{
				ways=(ways+(lf*rf)%mod)%mod;
			}
		}
		else if(s[k]=='&'){
			if(istrue){
				ways=(ways+(lt*rt)%mod)%mod;
			}
			else{
				ways=(ways+(lf*rf)%mod+(lt*rf)%mod+(lf*rt)%mod)%mod;
			}
		}
		else if(s[k]=='^'){
			if(istrue){
				ways=(ways+(lt*rf)%mod+(lf*rt)%mod)%mod;
			}
			else{
				ways=(ways+(lt*rt)%mod+(lf*rf)%mod)%mod;
			}
		}
	}
	dp[i][j][istrue]=ways%mod;
		}
	}
	}
	cout<<dp[0][n-1][1];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}