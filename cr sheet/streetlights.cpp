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
	ll n,k;
	cin>>n>>k;
	vector<pair<int,int>> arr(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr[i]={x-k,x+k};
	}
	sort(arr.begin(),arr.end());
	
	int index=0;
	for(int i=1;i<n;i++){
		int start=arr[i].first;
		int end=arr[i].second;
		if(start<=arr[index].second){
			arr[index].second=max(arr[index].second,arr[i].second);
		}
		else{
			index++;
			arr[index]=arr[i];
		}
	}
	
	int total_points=0;
	for(int i=0;i<=index;i++){
		total_points+=arr[i].second-arr[i].first+1;
	}
	cout<<total_points<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}