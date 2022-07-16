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
	int k=pat.size();
	int ans=0;
	int count=0;
	int i=0;
	int j=0;
	int n=str.size();
	unordered_map<char,int> mpp1,mpp2;
	for(auto x:pat){
		mpp1[x]++;
	}
	count=mpp1.size();
	while(j<n){
		if(mpp1.find(str[j])!=mpp1.end()){mpp1[str[j]]--;
			if(mpp1[str[j]]==0){
				count--;
			}
		}
		if(j-i+1<k){
			j++;
		}
		else if(j-i+1==k){
			
			if(!count)ans++;
			
			if(mpp1.find(str[i])!=mpp1.end())
				{
					mpp1[str[i]]++;
					count++;
				}
			i++;
			j++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}