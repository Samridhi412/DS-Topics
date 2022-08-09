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
unordered_map<string,ll> mp;
ll solve(ll n,ll m,ll k){
	if(n==0){
		return sum==0;
	}
	else if(sum<0){
		return 0;
	}
	string key=to_string(n)+"|"+to_string(k);
	if(mp.count(key)){
		return mp[key];
	}
	ll res=0;
	for(int i=1;i<=m;i++){
		res+=solve(n-1,m,k-i);
	}
	return mp[key]=res;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,k;
	cin>>n>>m>>k;
	cout<<solve(n,m,k);
	return 0;
}