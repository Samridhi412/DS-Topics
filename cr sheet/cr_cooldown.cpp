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
long f(long* values,int n,int ind,int buy,vector<vector<long>>& dp){
	if(ind>=n){
		return 0;
	}
	if(dp[ind][buy]!=-1)return dp[ind][buy];
	if(buy){
		return dp[ind][buy]=max(-values[ind]+f(values,n,ind+1,0,dp),f(values,n,ind+1,1,dp));
	}
	return dp[ind][buy]=max(values[ind]+f(values,n,ind+2,1,dp),f(values,n,ind+1,0,dp));
}
void solve(){
	int n;
	cin>>n;
	long values[n];
	for(int i=0;i<n;i++){
		cin>>values[i];
	}
	vector<vector<long>> dp2(n+1,vector<long>(2,-1));
	cout<<f(values,n,0,1,dp2)<<endl;
	// vector<vector<long>> dp(n+2,vector<long>(2,0));
	long prev1buy=0;
	long prev1notbuy=0;
	long prev2buy=0;
	long prev2notbuy=0;
	long currbuy,currnotbuy;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=1;j++){
			if(j==1)currbuy=max(-values[i]+prev2notbuy,prev2buy);
			else currnotbuy=max(values[i]+prev1buy,prev2notbuy);
		}
		prev1buy=prev2buy;
		prev1notbuy=prev2notbuy;
		prev2buy=currbuy;
		prev2notbuy=currnotbuy;
		
	}
	cout<<prev2buy;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}