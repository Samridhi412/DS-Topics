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
int solve(){
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int maxi=-1e9;
	int prod=1;
	for(int  i=0;i<n;i++){
		prod*=arr[i];
		maxi=max(maxi,prod);
		if(prod==0){
			prod=1;
		}
	}
	prod=1;
	for(int i=n-1;i>=0;i--){
		prod*=arr[i];
		maxi=max(maxi,prod);
		if(prod==0){
			prod=1;
		}
	}
	return maxi;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<solve();
	return 0;
}