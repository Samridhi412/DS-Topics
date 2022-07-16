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
	string str,pat;
	cin>>str>>pat;
	int i=0;
	int j=0;
	int n=str.size();
	unordered_map<char,int> mpp;
	for(auto x:pat){
		mpp[x]++;
	}
	int maxlen=INT_MAX;
	int count=mpp.size();
	while(j<n){
		if(mpp.find(str[j])!=mpp.end()){
			mpp[str[j]]--;
			if(mpp[str[j]]==0){
				count--;
			}
		}
	if(count==0){
		while(count==0){
			maxlen=min(maxlen,j-i+1);
			if(mpp.find(str[i])!=mpp.end()){
				mpp[str[i]]++;
			if(mpp[str[i]]>0){
				count++;
			}
			// else i++;
		}
	i++;
		// i++;
	}
	
	}
	j++;
}
	cout<<maxlen<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}