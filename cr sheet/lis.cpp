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
int f(int* values,int ind,int n,int prev_ind,vector<vector<int>>& dp){
	if(ind==n){
		return 0;
	}
	if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
	int len=f(values,ind+1,n,prev_ind,dp);
	if(prev_ind==-1||values[ind]>values[prev_ind]){
		len=max(len,1+f(values,ind+1,n,ind,dp));
	}
	return dp[ind][prev_ind+1]=len;
}
void tabulation(int* values,int n){
	vector<int> dp(n,1),hash(n);
	for(int i=0;i<n;i++){
		hash[i]=i;
	}
	int maxi=1;
	int last_ind=-1;
	for(int ind=0;ind<n;ind++){
		for(int prev=0;prev<ind;prev++){
			if(values[prev]<values[ind]&&dp[ind]<dp[prev]+1){
				dp[ind]=dp[prev]+1;
				hash[ind]=prev;
			}
		}
		if(dp[ind]>maxi){
			maxi=dp[ind];
			last_ind=ind;
		}
		
	}
	vector<int> temp;
	temp.push_back(values[last_ind]);
	while(hash[last_ind]!=last_ind){
		last_ind=hash[last_ind];
		temp.push_back(values[last_ind]);
	}
	reverse(temp.begin(),temp.end());
	cout<<maxi<<endl;
	for(auto &x:temp){
		cout<<x<<" ";
	}
	cout<<endl;
}
void solve(){
	int n;
	cin>>n;
	int values[n];
	for(int i=0;i<n;i++){
		cin>>values[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));//runtime error if n=1e5 bcoz 1e10 will be taken by dp 
	cout<<f(values,0,n,-1,dp);
	// vector<vector<int>> dp2(n+1,vector<int>(n+1,0));
	vector<int> prev(n+1,0),cur(n+1,0);
	for(int i=n-1;i>=0;i--){
		for(int j=i-1;j>=-1;j--){
			int len=prev[j+1];
			if(j==-1||values[i]>values[j]){
				len=max(len,1+prev[i+1]);
			}
			cur[j+1]=len;
		}
		prev=cur;
	}
	cout<<prev[-1+1];
	tabulation(values,n);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}