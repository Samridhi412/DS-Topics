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
ll dp[100][100][20][2];
void init_code(){
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109};
bool isprime(int even,int odd,int len){
	ll x=even-odd;
	if(len&1){
		x=odd-even;
	}
	if(x<0){
		return 0;
	}
	for(auto it:prime){
		if(it==x)return 1;
	}
	return 0;
}
ll g(string str,int even=0,int odd=0,int pos=0,int tight=1){
	if(pos>=str.size()){
		if(isprime(even,odd,str.size())){
			return 1;
		}
		else return 0;
	}
	else if(dp[even][odd][pos][tight]!=-1)return dp[even][odd][pos][tight];
	else if(tight){
		ll res=0;
		for(int i=0;i<=str[pos]-'0';i++){
			if(pos&1){
				odd+=i;
			}
			else{
				even+=i;
			}
			if(i==str[pos]-'0'){
				res+=g(str,even,odd,pos+1,1);
			}
			else{
				res+=g(str,even,odd,pos+1,0);
			}
		}
		dp[even][odd][pos][tight]=res;
		return res;
	}
	else{
		ll res=0;
	for(int i=0;i<=9;i++){
		if(pos&1){
				odd+=i;
			}
			else{
				even+=i;
			}
			res+=g(str,even,odd,pos+1,0);
	}	
	dp[even][odd][pos][tight]=res;
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