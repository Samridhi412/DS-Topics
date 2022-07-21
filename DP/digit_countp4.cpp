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
int dp[12][12];
void init_code(){
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
ll g(int n,vector<int>& digits,int prev=0,int pos=0,string temp=""){
	if(pos==n){
		cout<<temp<<endl;
		return 1;
	}
	else if(dp[pos][prev]!=-1)return dp[pos][prev];
	ll res=0;
	for(int i=0;i<digits.size();i++){
		if(prev==0||abs(prev-digits[i])<=2){
			res+=g(n,digits,digits[i],pos+1,temp+to_string(digits[i]));
		}
	}
	return dp[pos][prev]=res;
}
void solve(){
	read(m);
	read(n);
	vector<int> digits(m);
	for(int i=0;i<m;i++){
		cin>>digits[i];
	}
	fill(dp,-1);
	ll ans1=g(n,digits);
	cout<<ans1<<endl;
	
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