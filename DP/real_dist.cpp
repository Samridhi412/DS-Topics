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
#define read(x) int x; cin>>x;
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
ld pi=3.1415926535897932;
int dp[20][2][2];
void init_code(){
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
ll g(string str,ll pos=0,ll flag=0,ll tight=1){
	if(pos==str.size()){
		return flag;
	}
	else if(dp[pos][flag][tight]!=-1)return dp[pos][flag][tight];
	else if(tight){
		ll res=0;
		for(int i=0;i<=str[pos]-'0';i++){
			if(i==3){
				flag=1;
				}
			if(i==str[pos]-'0'){
				res+=g(str,pos+1,flag,1);
			}
			else{
				res+=g(str,pos+1,flag,0);
			}
		}
		dp[pos][flag][tight]=res;
		return res;
	}
	else{
		ll res=0;
		for(int i=0;i<=9;i++){
			if(i==3){
				flag=1;
			}
			res+=g(str,pos+1,flag,0);
		}
		dp[pos][flag][tight]=res;
		return res;
	}
}
void solve(){
	read(n);
	string a=to_string(n);
	ll ans=g(n);
	cout<<n-ans<<endl;
}
int main(){
	// init_code();
	IOS;
	ll t;
	cin>>t;
	rep(i,1,t+1){
		goog(i);
		solve();
	}
	return 0;
}