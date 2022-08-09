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
int ispal[10000][10000];
void ispalindrome(string& s){
	int n=s.size();
	for(int i=0;i<n;i++){
		ispal[i][i]=1;
	}
	for(int gap=1;gap<n;gap++){
		for(int i=0,j=gap;j<n;i++,j++){
			if(s[i]==s[j]&&ispal[i+1][j-1]){
				ispal[i][j]=1;
			}
		}
	}
	
}
int minimum_partitions(string& s,int i,vector<int>& dp){
	if(i==s.size()){
		return 0;
	}
	else if(dp[i]!=-1)return dp[i];
	int mini=INT_MAX;
	for(int k=i;k<s.size();k++){
		if(ispal[i][k]){
			mini=min(mini,1+minimum_partitions(s,k+1,dp));
		}
	}
	return dp[i]=mini;
}
void solve(){
	string s;
	getline(cin,s);
	int n=s.size();
	memset(ispal,0,sizeof ispal);
	ispalindrome(s);
	vector<int> dpp(n,-1);
	cout<<minimum_partitions(s,0,dpp)-1;
	vector<int> dp(n+1,0);
	dp[n]=0;
	for(int i=n-1;i>=0;i--){
		int mini=INT_MAX;
		for(int k=i;k<s.size();k++){
			if(ispal[i][k]){
				mini=min(mini,1+dp[k+1]);
			}
		}
		 dp[i]=mini;
	}
	cout<<dp[0]-1;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}