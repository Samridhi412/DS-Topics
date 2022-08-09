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
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());
	vector<int> dp(n,1),hash(n);
	int lastindex=-1;
	int maxi=-1;
	for(int i=0;i<n;i++){
		hash[i]=i;
		for(int j=0;j<i;j++){
			if(arr[i]%arr[j]==0&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
				hash[i]=j;
			}
		}
		if(dp[i]>maxi){
			maxi=dp[i];
			lastindex=i;
		}
	}
	vector<int> temp;
	while(lastindex!=hash[lastindex]){
		temp.push_back(arr[lastindex]);
		lastindex=hash[lastindex];
	}
	for(auto x:temp){
		cout<<x<<" ";
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}