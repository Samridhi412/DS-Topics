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
int max_coins(vector<int> baloons,int i,int j,vector<vector<int>>& dp){
	if(i>j)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int maxi=INT_MIN;
	for(int ind=i;ind<=j;ind++){
		int cost=baloons[i-1]*baloons[j+1]*baloons[ind]+max_coins(baloons,i,ind-1,dp)+max_coins(baloons,ind+1,j,dp);
		maxi=max(maxi,cost);
	}
	return dp[i][j]=maxi;
}
void solve(){
	int n;
	cin>>n;
	vector<int> baloons(n);
	for(int i=0;i<n;i++){
		cin>>baloons[i];
	}
	baloons.push_back(1);
	baloons.insert(baloons.begin(),1);
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	cout<<max_coins(baloons,1,n,dp);
	vector<vector<int>> dp2(n+2,vector<int>(n+2,0));
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(i>j)continue;
			int maxi=INT_MIN;
				for(int ind=i;ind<=j;ind++){
					int cost=baloons[i-1]*baloons[j+1]*baloons[ind]+dp2[i][ind-1]+dp2[ind+1][j];
					maxi=max(maxi,cost);
				}
				dp2[i][j]=maxi;
		}
	}
	cout<<dp2[1][n];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}