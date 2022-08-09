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
ll solve(ll sum){
	if(sum<=0){
		return 0;
	}
	 ll mini=-1e9;
	for(int i=1;i*i<=sum;i++){
		ll cnt=1+solve(sum-i*i);
		mini=min(mini,cnt);
	}
	return mini;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll sum;
	cin>>sum
	cout<<solve(sum);
	return 0;
}