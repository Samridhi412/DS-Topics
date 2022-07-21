#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mii map<int, int>
#define pii pair<int, int>
#define ff first
#define ss second 
#define fill(a,b) memset(a,b,sizeof(a))
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define print2d(dp,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<dp[i][j]<<" ";cout<<"\n";}
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
#define prDouble(x) cout<<fixed<<setprecision(10)<<x;
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout<<"Case #"<<tno<<": "
#define mp make_pair
#define pb push_back
#define endl "\n"
#define read(x) ll x; cin>>x;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
ld pi=3.1415926535897932;
int dp[10][80][2];
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109};
void init_code(){
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
bool isprime(ll val){
	for(auto x:prime){
		if(val==x)return true;
	}
	return false;
}
ll g(string str,ll pos=0,ll tight=1,ll sum=0){
	if(pos==str.size()){
		if(isprime(sum)){
			return 1;
		}
		return 0;
	}
	else if(dp[pos][sum][tight]!=-1)return dp[pos][sum][tight];
	else if(tight){
		ll res=0;
		for(int i=0;i<=str[pos]-'0';i++){
			if(i==str[pos]-'0'){
				res+= g(str,pos+1,1,sum+i);
			}
			else{
				res+= g(str,pos+1,0,sum+i);
			}
		}
		dp[pos][sum][tight]=res;
		return res;
	}
	else{
		ll res=0;
		for(int i=0;i<=9;i++){
			res+= g(str,pos+1,0,sum+i);
		}
		dp[pos][sum][tight]=res;
		return res;
	}
}
void solve(){
	read(l);
	read(r);
	l=l-1;
	string a=to_string(l);
	string b=to_string(r);
	fill(dp,-1);
	ll ans1=g(a);
	fill(dp,-1);
	ll ans2=g(b);
	cout<<ans2-ans1<<endl;
}
int main(){
	IOS;
	ll t;
	cin>>t;
	rep(i,1,t+1){
		goog(i);
		solve();
	}
	return 0;
}