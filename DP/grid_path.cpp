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
	ll n,m;
	cin>>n>>m;
	vector<vector<char>> mat(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	vector<vector<int>> dp(n,vector<int>(m,0));
	dp[n-1][m-1]=1;
	for(int i=m-2;i>=0;i--){
		
		if(mat[n-1][i]!='*')
			{
				dp[n-1][i]=dp[n-1][i+1];
			}
	}
	for(int i=n-2;i>=0;i--){
		if(mat[i][m-1]!='*'){
			dp[i][m-1]=dp[i+1][m-1];
		}
	}
	
	for(int i=n-2;i>=0;i--){
		for(int j=m-2;j>=0;j--){
			if(mat[i][j]!='*'){
			dp[i][j]=dp[i+1][j]+dp[i][j+1];
		}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[0][0];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}