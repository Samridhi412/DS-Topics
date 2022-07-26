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
ll dp[20][180][2];
// if number has 18 digits--->18
// 	if all digits are 9 then u get maximum sum-->9*8=72-->80
// 		tight=2---->restriction/ not
void init_code(){
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
ll g(string str,ll pos=0,ll tight=1,ll sum=0){
	if(pos==str.size()){
		// cout<<sum<<endl;
		return sum;
	}
	else if(dp[pos][sum][tight]!=-1)return dp[pos][sum][tight];
	else if(tight){
		ll res=0;
		for(int i=0;i<=str[pos]-'0';i++){
			if(i==str[pos]-'0'){
				res+=g(str,pos+1,1,sum+i);
			}
			else res+=g(str,pos+1,0,sum+i);
		}
		dp[pos][sum][tight]=res;
		return res;
	}
	else{
		ll res=0;
		for(int i=0;i<=9;i++){
			res+=g(str,pos+1,0,sum+i);
		}
		
		dp[pos][sum][tight]=res;
		return res;
	}
}
void solve(){
	read(l);
	read(r);
	l=l-1;
	string a=to_string(r);
	string b=to_string(l);
	fill(dp,-1);
	ll ans=g(a);
	fill(dp,-1);
	ll ans1=g(b);
	cout<<ans-ans1<<endl;
	
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