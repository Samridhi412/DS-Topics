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
void lbs(vector<int>& arr,int n){
	vector<int> dp(n,1),dp1(n,1),hash(n),hash1(n);
	int lastindex=-1;
	int maxi=-1;
	for(int i=0;i<n;i++){
		hash[i]=i;
		for(int prev=0;prev<i;prev++){
			if(arr[i]>arr[prev]&&dp[i]<dp[prev]+1){
				dp[i]=dp[prev]+1;
				hash[i]=prev;
			}
		}
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	for(int i=n-1;i>=0;i--){
		hash1[i]=i;
		for(int prev=n-1;prev>i;prev--){
			if(arr[i]>arr[prev]&&dp1[i]<dp1[prev]+1){
				dp1[i]=dp1[prev]+1;
				hash1[i]=prev;
			}
		}
		// cout<<dp1[i]<<" ";
	}
	cout<<endl;
	int mlen=0;
	for(int i=0;i<n;i++){
		int len=dp[i];
		dp[i]=dp[i]+dp1[i]-1;
		// cout<<dp[i]<<" ";
		if(dp[i]>maxi){
			maxi=dp[i];
			lastindex=i;
			mlen=len;
		}
	}
	cout<<endl;
	cout<<lastindex<<endl;
	int temp[maxi];
	temp[mlen-1]=arr[lastindex];
	int ind=mlen-2;
	int lind=lastindex;
	// lastindex=hash[lastindex];
	while(lastindex!=hash[lastindex]){
		lastindex=hash[lastindex];
		temp[ind]=arr[lastindex];
		
		ind--;
	}
	ind=mlen;
	// lind=hash1[lind];
	while(lind!=hash1[lind]){
		lind=hash1[lind];
		temp[ind]=arr[lind];
		
		ind++;
	}
	for(auto x:temp){
		cout<<x<<" ";
	}
}
void solve(){
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	lbs(arr,n);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}