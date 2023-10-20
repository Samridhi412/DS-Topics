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
	ll n,p;
	cin>>n>>p;
	int arr[p+1];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++){
		int x,r;
		cin>>x>>r;
		if(x-r>=0){
			arr[x-r]++;
		}
		else arr[0]++;
		if(x+r+1<=p){
			arr[x+r+1]--;
		}
	}
	for(int i=1;i<=p;i++){
		arr[i]+=arr[i-1];
	}
	int ans=1e-9;
	for(int i=0;i<=p;i++){
		int cnt=0;
		while(arr[i]!=1&&i<=p){
			cnt++;
			i++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}