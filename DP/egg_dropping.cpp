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
int egg_dropping(int eggs,int floors,vector<vector<int>>& dp){
	if(eggs==1)return floors;
	else if(floors==0||floors==1)return floors;
	else if(dp[eggs][floors]!=-1)return dp[eggs][floors];
	int mini=INT_MAX;
	for(int i=1;i<=floors;i++){
		int low,high;
		if(dp[eggs-1][i-1]!=-1){
			low=dp[eggs-1][i-1];
		}
		else{
			dp[eggs-1][i-1]=egg_dropping(eggs-1,i-1,dp);
		}
		if(dp[eggs][floors-i]!=-1){
			high=dp[eggs][floors-i];
		}
		else{
			dp[eggs][floors-i]=egg_dropping(eggs,floors-i,dp);
		}
		int temp=1+max(low,high);
	      mini=min(mini,temp);
	}
	return dp[eggs][floors]=mini;
}
void solve(){
	ll eggs,floors;
	cin>>eggs>>floors;
	vector<vector<int>> dp(eggs+1,vector<int>(floors,-1));
	egg_dropping(eggs,floors,dp);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}