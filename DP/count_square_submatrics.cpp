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
	int dp[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>dp[i][i];
		}
	}
	int mat[n][n];
	int count=0;
	for(int i=0;i<n;i++){
		mat[i][0]=dp[i][0];
		count+=mat[i][0];
	}
	for(int i=0;i<n;i++){
		mat[0][i]=dp[0][i];
		count+=mat[0][i];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(dp[i][j]==1){
				mat[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
			}
			else{
				mat[i][j]=0;
			}
			count+=mat[i][j];
		}
	}
	cout<<count;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}