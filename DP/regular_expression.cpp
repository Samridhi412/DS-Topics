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
bool regular_expression(string &s,string &t,int i,int j,vector<vector<int>>& dp){
	if(i<0&&j<0)return true;
	else if(j<0&&i>=0)return false;
	else if(j>=0&&i<0){
		if(t[j]=='*'){
		return regular_expression(s,t,i,j-2,dp);
	}
	return false; 
	}
	else if(dp[i][j]!=-1)return dp[i][j];
	else if(s[i]==t[j]||t[j]=='.'){
		return dp[i][j]=regular_expression(s,t,i-1,j-1,dp);
	}
	else if(j>=1&&t[j]=='*'){
		bool a=false;
		if(t[j-1]=='.'||t[j-1]==s[i]){
		 a= regular_expression(s,t,i-1,j,dp);
	    }
	    	return dp[i][j]=a || regular_expression(s,t,i,j-2,dp);
	    
	}
	return dp[i][j]=false;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s,t;
	// cin.ignore();
	getline(cin,s);
	getline(cin,t);
	int n=s.size();
	int m=t.size();
	
	vector<vector<int>> dpp(n,vector<int>(m,-1));
	cout<<regular_expression(s,t,s.size()-1,t.size()-1,dpp);
	int dp[m+1][n+1];
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[0][i]=0;
	}
	dp[1][0]=0;
	for(int i=2;i<=m;i++){
		if(t[i-1]=='*'){
			dp[i][0]=dp[i-2][0];
		}
		else{
			dp[i][0]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(t[i-1]==s[j-1]||t[i-1]=='.'){
				dp[i][j]=dp[i-1][j-1];
			}
			else if(i>=2&&t[i-1]=='*'){
				dp[i][j]=dp[i-2][j];
				if(t[i-2]==s[j-1]||t[i-2]=='.'){
					dp[i][j]=dp[i][j]|dp[i][j-1];
				}
			}
			else{
				dp[i][j]=0;
			}
		}
	}
	cout<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			// cout<<t[i-1]<<" "<<s[j-1]<<endl;
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[m][n];
	return 0;
}