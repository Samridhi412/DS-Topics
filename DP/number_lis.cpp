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
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> dp(n,1),count(n,1);
	int maxi=-1;
	int nlis=0;
	for(int i=0;i<n;i++){
		for(int prev=0;prev<i;prev++){
			if(arr[i]>arr[prev]){
				if(dp[i]==dp[prev]+1){
					count[i]+=count[prev];
				}
				else if(dp[i]<dp[prev]+1){
				dp[i]=dp[prev]+1;
				count[i]=count[prev];
			}
			}
		}
		if(dp[i]>maxi){
			maxi=dp[i];
			nlis=count[i];
		}
		else if(dp[i]==maxi){
			nlis+=count[i];
		}
	}
	cout<<maxi<<" "<<nlis;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}