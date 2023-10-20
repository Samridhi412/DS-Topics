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
void longest_bitonic_subsequence(int* values,int n){
	vector<int> dp1(n,1);
	vector<int> hash1(n),hash2(n);
	vector<int> dp2(n,1);
	for(int i=0;i<n;i++){
		hash1[i]=hash2[i]=i;
	}
	int maxi=1;
	int last_ind=-1;
	for(int ind=0;ind<n;ind++){
		for(int prev=0;prev<ind;prev++){
			if(values[ind]>values[prev]&&dp1[ind]<dp1[prev]+1){
				dp1[ind]=dp1[prev]+1;
				hash1[ind]=prev;
			}
		}
	}
	for(int ind=n-1;ind>=0;ind--){
		for(int prev=n-1;prev>ind;prev--){
			if(values[ind]>values[prev]&&dp2[ind]<dp2[prev]+1){
				dp2[ind]=dp2[prev]+1;
				hash2[ind]=prev;
			}
		}
		if(dp1[ind]+dp2[ind]-1>maxi){
			maxi=dp1[ind]+dp2[ind]-1;
			last_ind=ind;
		}
	}
	vector<int> temp;
	temp.push_back(values[last_ind]);
	int lastt=last_ind;
	while(hash1[last_ind]!=last_ind){
		last_ind=hash1[last_ind];
		temp.push_back(values[last_ind]);
	}
	reverse(temp.begin(),temp.end());
	while(hash2[lastt]!=lastt){
		lastt=hash2[lastt];
		temp.push_back(values[lastt]);
	}
	cout<<maxi<<endl;
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
	longest_bitonic_subsequence(values,n);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}