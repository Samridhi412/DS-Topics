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
int min_cost_cut_stick(vector<int>& cuts,int i,int j,vector<vector<int>>& dp){
	if(i>j)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int mini=INT_MAX;
	for(int ind=i;ind<=j;ind++){
		int cost=cuts[j+1]-cuts[i-1]+min_cost_cut_stick(cuts,i,ind-1,dp)+min_cost_cut_stick(cuts,ind+1,j,dp);
		mini=min(mini,cost);
	}
	return dp[i][j]=mini;
}
void solve(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int> cuts(m);
	for(int i=0;i<m;i++){
		cin>>cuts[i];
	}
	cuts.push_back(n);
	cuts.insert(cuts.begin(),0);
	sort(cuts.begin(),cuts.end());
	vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
	cout<<min_cost_cut_stick(cuts,1,m,dp);
	vector<vector<int>> dp2(m+2,vector<int>(m+2,0));
	for(int i=m;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(i>j)continue;
			int mini=INT_MAX;
				for(int ind=i;ind<=j;ind++){
					int cost=cuts[j+1]-cuts[i-1]+dp2[i][ind-1]+dp2[ind+1][j];
					mini=min(mini,cost);
				}
				dp2[i][j]=mini;
		}
	}
	cout<<dp2[1][m]<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}