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
int allocate_jobs(int mat[][100],int n,int person,int mask,vector<vector<int>>& dp){
	if(person==n){
		return 0;
	}
	else if(dp[person][mask]!=-1)return dp[person][mask];
	int mini=1e9;
	for(int i=0;i<n;i++){
		if(mask&(1<<i)){
			int cost=mat[person][i]+allocate_jobs(mat,n,person+1,mask^(1<<i),dp);
			mini=min(mini,cost);
		}
	}
	return dp[person][mask]=mini;
	
}
void solve(){
	ll n;
	cin>>n;
	int mat[100][100];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}
	vector<vector<int>> dp(n,vector<int>(1<<n,-1));
	cout<<allocate_jobs(mat,n,0,(1<<n)-1,dp);
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}