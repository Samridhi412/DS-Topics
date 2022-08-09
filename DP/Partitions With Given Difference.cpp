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
int countPartitions(int n, int d, vector<int> &arr) {
	ll total_sum=0;
	for(int i=0;i<n;i++){
		total_sum+=arr[i];
	}
	vector<int> prev(total_sum+1,0),curr(total_sum+1,0);
	if(arr[0]<=total_sum)prev[arr[0]]=1;
	prev[0]=curr[0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=total_sum;j++){
			curr[j]=prev[j];
			if(arr[i]<=j){
				curr[j]+=prev[j-arr[i]];
			}
		}
		prev=curr;
	}
	ll count=0;
	for(int i=total_sum;i>=total_sum/2;i--){
		ll s2=i-d;
		if(prev[s2]!=0){
			count+=prev[s2];
		}
	}
	cout<<count;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,d;
	cin>>n>>d;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	countPartitions(n,d,arr);
	return 0;
}