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
int partition_maxsum(vector<int>& arr,int i,int kk,int n){
	if(i==n){
		return 0;
	}
	int maxval=0;
	int len=0;
	int maxsum=-1e9;
	for(int k=i;k<min(i+kk,n);k++){
	 maxval=max(maxval,arr[k]);
	 len++;
	 maxsum=max(maxsum,len*maxval+partition_maxsum(arr,k+1,kk,n));
	}
	return maxsum;
}
void solve(){
	ll n,kk;
	cin>>n;
	vector<int> arr(n);
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>kk;
	vector<int> dp(n+1,0);
	cout<<partition_maxsum(arr,0,kk,n);
	for(int i=n-1;i>=0;i--){
		int maxval=0;
		int len=0;
		int maxsum=-1e9;
		for(int k=i;k<min(i+kk,n);k++){
		 maxval=max(maxval,arr[k]);
		 len++;
		 maxsum=max(maxsum,len*maxval+dp[k+1]);
		}
		dp[i]=maxsum;
	}
	cout<<dp[0];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}