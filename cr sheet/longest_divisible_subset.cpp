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
void longest_div_subset(int* values,int n){
	vector<int> dp(n,1),hash(n);
	for(int i=0;i<n;i++){
		hash[i]=i;
	}
	int maxi=1;
	int last_ind=-1;
	for(int ind=0;ind<n;ind++){
		for(int prev=0;prev<ind;prev++){
			if(values[ind]%values[prev]==0&&dp[prev]+1>dp[ind]){
				dp[ind]=dp[prev]+1;
				hash[ind]=prev;
				
			}
		}
		if(dp[ind]>maxi){
			maxi=dp[ind];
			last_ind=ind;
		}
	}
	cout<<maxi<<endl;
	vector<int> temp;
	temp.push_back(values[last_ind]);
	while(last_ind!=hash[last_ind]){
		last_ind=hash[last_ind];
		temp.push_back(values[last_ind]);
	}
	reverse(temp.begin(),temp.end());
	for(auto &x:temp){
		cout<<x<<" ";
	}
	cout<<endl;
}
void solve(){
	int n;
	cin>>n;
	int values[n];
	for(int i=0;i<n;i++){
		cin>>values[i];
	}
	sort(values,values+n);
	longest_div_subset(values,n);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}