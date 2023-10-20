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
void number_increasing_sub(int* values,int n){
	vector<int> dp(n,1);
	vector<int> count(n,1);
	int maxi=1;
	for(int ind=0;ind<n;ind++){
		for(int prev=0;prev<ind;prev++){
			if(values[ind]>values[prev]&&1+dp[prev]>dp[ind]){
				dp[ind]=dp[prev]+1;
				count[ind]=count[prev];
			}
			else if(values[ind]>values[prev]&&1+dp[prev]==dp[ind]){
				count[ind]+=count[prev];
			}
		}
		maxi=max(maxi,dp[ind]);
	}
	for(auto &h:dp){
		cout<<h<<" ";
	}
	cout<<endl;
	for(auto &y:count){
		cout<<y<<" ";
	}
	cout<<endl;
	int ans=0;
	cout<<maxi<<endl;
	for(int i=0;i<n;i++){
		if(dp[i]==maxi){
			ans+=count[i];
		}
	}
	cout<<ans<<endl;
}
void solve(){
	int n;
	cin>>n;
	int values[n];
	for(int i=0;i<n;i++){
		cin>>values[i];
	}
	number_increasing_sub(values,n);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}