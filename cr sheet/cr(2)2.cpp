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
	ll n,p;
	cin>>n>>p;
	if(p==0){
		cout<<"0"<<endl;
		return;
	}
	else if(n==0){
		cout<<p+1<<endl;
		return;
	}
	int arr[p+1]={0};
	for(int i=0;i<n;i++){
		int start,end;
		cin>>start>>end;
		for(int j=start-end;j<=start+end;j++){
			if(j<0||j>p)continue;
			arr[j]++;
		}
	}
	
	for(int i=0;i<=p;i++){
		if(arr[i]!=1){
			arr[i]=0;
		}
	}
	
	// map<int,int> mp;
	// int sum=0;
	// int maxlen=0;
	// for(int i=0;i<=p;i++){
	// 	sum+=arr[i];
	// 	if(sum==0){
	// 		maxlen=i+1;
	// 		continue;
	// 	}
	// 	if(arr[i]==0){
	// 		maxlen=1;
	// 	}
	// 	if(mp.find(sum)!=mp.end()){
	// 		maxlen=max(maxlen,i-mp[sum]+1);
	// 		continue;
	// 	}
	// 	mp[sum]=i;
		
	// }
	// cout<<maxlen<<endl;
	int ans=INT_MIN;
	for(int i=0;i<=p;i++){
		int cnt=0;
		while(arr[i]!=1&&i<=p){
			cnt++;
			i++;
		}
		ans=max(ans,cnt);
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