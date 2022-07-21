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
int dp[1001][1001][2];
vector<int> dogs[1001];
void init_code(){
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
int solve2(int x,int k,bool isround){
	if(k<=0){return 0;}
	if(x==1001)return 1e9;
	if(dp[x][k][isround]!=-1)return dp[x][k][isround];
	int ans=solve2(x+1,k,isround);
	for(int j=0;j<dogs[x].size();j++){
		if(!isround)
		  ans=min(ans,dogs[x][j]+solve2(x+1,k-(j+1),1));
		ans=min(ans,2*dogs[x][j]+solve2(x+1,k-(j+1),isround));
	}
	return dp[x][k][isround]=ans;	
	
}
void solve(){
	read(n);
	read(k);
	vector<int> positions(n),color(n);
	rep(i,0,n){
		cin>>positions[i];
	}
	rep(i,0,n){
		cin>>color[i];
	}
	rep(i,0,1001){
		dogs[i].clear();
	}
	rep(i,0,n){
		dogs[color[i]].push_back(positions[i]);
	}
	rep(i,0,1001){
		sort(all(dogs[i]));
	}
	fill(dp,-1);
	cout<<solve2(1,k,0)<<endl;
	
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