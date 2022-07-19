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
int dp[1001][1001];
set<pair<int,int>> vis;
void init_code(){
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
int solve2(int i,int j,int n){
	if(i>n)return 1e5;
	if(i==n){
		return 0;
	}
	if(vis.find({i,j})!=vis.end())return 1e5;
	vis.insert({i,j});
	if(dp[i][j]!=-1)return dp[i][j];
	int op1=1+solve2(i,i,n);
	int op2=1+solve2(i+j,j,n);
	return dp[i][j]=min(op1,op2);
}
void solve(){
	read(n);
	fill(dp,-1);
	cout<<solve2(1,0,n);
	
}
int main(){
	IOS;
	solve();
	return 0;
}