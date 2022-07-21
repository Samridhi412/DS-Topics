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
void init_code(){
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	read(n);
	if(n==1){
		cout<<2<<endl;
	}
	else
	{
		ll dp[n+2][2];
		dp[n+1][1]=dp[n+1][0]=1;
		for(int i=n;i>=2;i--){
			ll op1=dp[i+1][1]+dp[i+1][0];
			ll op2=dp[i+1][0];
			ll op3=2*dp[i+1][0];
			ll op4=dp[i+1][1];
			dp[i][0]=(op1+op2+op3)%mod;
			dp[i][1]=(op1+op4)%mod;
			}
			cout<<dp[2][0]+dp[2][1]<<endl;
	}
}
int main(){
	IOS; 
	solve();
	return 0;
}