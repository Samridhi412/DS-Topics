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
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	pair<int,int> arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr,arr+n);
	for(auto x:arr){
		cout<<x.first<<" "<<x.second<<endl;
	}
	cout<<endl<<endl<<endl;
	int lis[n];
	// memset(lis,1,sizeof(lis));
	for(int i=0;i<n;i++){
		lis[i]=1;
	}
	// cout<<endl;
	int maxi=-1e5;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j].second<arr[i].second){
				lis[i]=max(lis[i],lis[j]+1);
			}
		}
		// cout<<lis[i]<<endl;
		maxi=max(maxi,lis[i]);
	}
	cout<<maxi<<endl;
	return 0;
}