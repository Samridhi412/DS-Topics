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
	string str;
	cin>>str;
	int k;
	int i=0,j=0;
	cin>>k;
	int n=str.size();
	int longest_sub=0;
	unordered_map<char,int> mpp;
	while(j<n){
		mpp[str[j]]++;
		if(mpp.size()<k){
			j++;
		}
		else if(mpp.size()==k){
			longest_sub=max(longest_sub,j-i+1);
			j++;
		}
		else{
			while(mpp.size()>k){
				mpp[str[i]]--;
				if(mpp[str[i]]==0){
					mpp.erase(str[i]);
				}
				i++;
			}
			if(longest_sub==k){
			longest_sub=max(longest_sub,j-i+1);	
			}
			j++;
		}
	}
	cout<<longest_sub<<endl;
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