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
ll max_sum(vector<vector<int>>& mat,int n,int i,vector<int>& dp){
	if(i>=n)return 0;
	else if(dp[i]!=-1)return dp[i];
	int take=max(mat[0][i],mat[1][i])+max_sum(mat,n,i+2);
	int nontake=max_sum(mat,n,i+1);
	return dp[i]=max(take,nontake);
}
void solve(){
	ll n;
	cin>>n;
	vector<vector<int>> mat(2,vector<int>(n));
	vector<int> dp(n,-1);
	for(int i=0;i<2;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}
	cout<<max_sum(mat,n,0,dp);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}