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
struct project{
	int starttime;
	int endtime;
	int reward;
};
bool cmp(project& p1,project& p2){
	return p1.endtime<p2.endtime;
}
void solve(){
	ll n;
	cin>>n;
	vector<project> arr(n);
	vector<int> endtm;
	for(int i=0;i<n;i++){
		cin>>arr[i].starttime;
		cin>>arr[i].endtime;
		cin>>arr[i].reward;
	}
	vector<int> dp(n+1);
	dp[0]=0;
	sort(arr.begin(),arr.end(),cmp);
	for(auto x:arr){
		endtm.push_back(x.endtime);
	}
	for(int i=1;i<=n;i++){
		auto it=lower_bound(endtm.begin(),endtm.end(),arr[i].starttime);
		int j;
		if(it==endtm.begin()){
			j=0;
		}
		else{
			it--;
			j=it-endtm.begin();
		}
		dp[i]=max(dp[i-1],arr[i].reward+dp[j]);
	}
	cout<<dp[n];
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