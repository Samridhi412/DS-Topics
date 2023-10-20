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
int partition_array(vector<int>& arr,int n,int k,int i,vector<int>& dp){
	if(i==n){
		return 0;
	}
	if(dp[i]!=-1)return dp[i];
	int maxi=INT_MIN;
	int max_ele=INT_MIN;
	for(int ind=i;ind<min(i+k,n);ind++){
		max_ele=max(max_ele,arr[ind]);
		maxi=max(maxi,max_ele*(ind-i+1)+partition_array(arr,n,k,ind+1,dp));
	}
	return dp[i]=maxi;
}
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> dp2(n,-1);
	cout<<partition_array(arr,n,k,0,dp2)<<endl;
	vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;i--){
    int maxi=INT_MIN;
	int max_ele=INT_MIN;
	for(int ind=i;ind<min(i+k,n);ind++){
		max_ele=max(max_ele,arr[ind]);
		maxi=max(maxi,max_ele*(ind-i+1)+dp[ind+1]);
	}
	dp[i]=maxi;
    }
    cout<< dp[0];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}