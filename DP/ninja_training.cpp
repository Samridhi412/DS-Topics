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
ll dp[100000][4];
ll max_merit(vector<vector<int>>& ninja,int ind,int activity){
	if(n==0){
		long long maxi=INT_MIN;
		for(int task=0;task<3;task++){
			if(task!=activity){
				maxi=max(maxi,ninja[0][task];)
			}
		}
		return maxi;
	}
	if(dp[ind][activity]!=-1)return dp[ind][activity];
	ll maxi=INT_MIN;
	for(int i=0;i<=2;i++){
		if(activity==i)continue;
		maxi=max(maxi,ninja[ind][i]+max_merit(ninja,ind-1,i));
		
	}
	return dp[ind][activity]=maxi;
}
void solve(){
	ll n;
	cin>>n;
	vector<vector<int>> ninja(n,vector<int>(3));
	for(int i=0;i<n;i++){
		cin>>ninja[i][0]>>ninja[i][1]>>ninja[i][2];
	}
	
	memset(dp,-1,sizeof dp);
	cout<<max_merit(ninja,n-1,3);
	memset(dp,0,sizeof dp);
	dp[0][0]=max(dp[0][1],dp[0][2]);
	dp[0][1]=max(dp[0][0],dp[0][2]);
	dp[0][2]=max(dp[0][0],dp[0][1]);
	dp[0][3]=max({dp[0][0],dp[0][1],dp[0][2]});
	for(int i=1;i<n;i++){
		
		for(int k=0;k<3;k++){
			ll maxi=INT_MIN;
			for(int l=0;l<3;l++){
				if(l==k)continue;
				maxi=max(maxi,dp[i-1][l]+ninja[i][l]);
			}
			dp[i][k]=maxi;
		}
	}
	cout<<dp[n-1][3];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}