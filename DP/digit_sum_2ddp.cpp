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
int dp[20][2];
void init_code(){
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
ll c(string& str,int n,int tight){
	if(!tight){
		return (pow(10,n)+0.1);
	}
	if(n==0){
		return 1;
	}
	ll ans=0;
	int ub=str[str.size()-n]-'0';
	for(int i=0;i<=ub;i++){
		ans+=c(str,n-1,(tight&&(i==ub)));
	}
	return ans;
}
ll g(string& str,int n,int tight){
	if(n==0){
		return 0;
	}
	else if(dp[n][tight]!=-1)return dp[n][tight];
	int ub=tight?str[str.size()-n]-'0':9;
	ll ans=0;
	for(int i=0;i<=ub;i++){
	ans+=i*c(str,n-1,(tight&&(i==ub)));
	ans+=g(str,n-1,(tight&&(i==ub)));	
	}
	dp[n][tight]=ans;
	return ans;
}
void solve(){
	read(l);
	read(r);
	if(l!=0)l=l-1;
	string a=to_string(l);
	string b=to_string(r);
	fill(dp,-1);
	ll ans1=g(a,a.size(),1);
	fill(dp,-1);
	ll ans2=g(b,b.size(),1);
	cout<<ans2-ans1<<endl;
}
int main(){
			IOS;
			solve();
	return 0;
}