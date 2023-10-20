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
	ll n,q;
	cin>>n>>q;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	for(int j=1;j<n;j++){
		arr[j]+=arr[j-1];
	}
	
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		if(a==1)cout<<arr[b-1]<<endl;
		else cout<<arr[b-1]-arr[a-2]<<endl;
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	// cout<<"hello";
	return 0;
}