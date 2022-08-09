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
ll linear_sol(ll sum,int ind,vector<int>& arr){
	if(sum==0)return 1;
	if(ind==0){
		if(sum%arr[ind]==0){
			return 1;
		}
		return 0;
	}
	res+=linear_sol(sum,ind-1,arr);
	if(sum<arr[ind]){
	res+=linear_sol(sum-arr[ind],ind,arr);
	}
	return res;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ll sum;
	cin>>sum;
	cout<<linear_sol(sum,n-1,arr);
	
	return 0;
}