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
int get(map<int,int>& mp,int v){
	auto it=mp.lower_bound(v);
	if(it==mp.begin()){
		return 0;
	}
	it--;
	return it->second;
}
void insert(map<int,int>& mp,int v,int adv){
	mp[v]=adv;
	auto it=mp.find(v);
	it++;
	while(it!=mp.end()&&it->second<=adv){
		auto temp=it;
		it++;
		mp.erase(temp);
	}
}
void optimal(){
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	map<int,int> mpp;
	vector<int> dp(n);
	dp[0]=1;
	mpp[arr[0]]=1;
	for(int i=1;i<n;i++){
		dp[i]=1+get(mpp,arr[i]);
		insert(mpp,arr[i],dp[i]);
	}
	int ans=*max_element(dp.begin(),dp.end());
	cout<<ans;
}
void solve(){
	// ll n;
	// cin>>n;
	// vector<int> arr(n);
	// for(int i=0;i<n;i++){
	// 	cin>>arr[i];
	// }
	// vector<int> dp(n,1);
	// int maxlen=1;
	// for(int i=1;i<n;i++){
	// 	for(int j=0;j<i;j++){
	// 		if(arr[j]<arr[i]){
	// 			dp[i]=max(dp[i],1+dp[j]);
	// 		}
	// 	}
	// 	maxlen=max(maxlen,dp[i]);
	// }
	// cout<<maxlen;
	optimal();
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}