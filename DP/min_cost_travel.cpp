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
unordered_set<int> travel_days;
unordered_map<int,int> passes;
int dp[366][4][366];
void init_code(){
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
int solve2(int dno,int pass,int buylast,vector<int>& cost){
	if(dno==366){return 0;}
	
	if(travel_days.find(dno)==travel_days.end()){return solve2(dno+1,pass,buylast,cost);}
	if(dp[dno][pass][buylast]!=-1)return dp[dno][pass][buylast];
	else{
		if(dno<buylast+passes[pass]){
			return dp[dno][pass][buylast]=solve2(dno+1,pass,buylast,cost);
		}
		else{
			int op1=cost[0]+solve2(dno+1,1,dno,cost);
			int op2=cost[1]+solve2(dno+1,2,dno,cost);
			int op3=cost[2]+solve2(dno+1,3,dno,cost);
			return dp[dno][pass][buylast]=min({op1,op2,op3});
		}
	}
}
void solve(){
	travel_days.clear();
	passes.clear();
	read(n);
	vector<int> days(n);
	rep(i,0,n){
		cin>>days[i];
		travel_days.insert(days[i]);
	}
	vector<int> cost(3);
	rep(i,0,3){
		cin>>cost[i];
	}
	passes[0]=0;
	passes[1]=cost[0];
	passes[2]=cost[1];
	passes[3]=cost[2];
	fill(dp,-1);
	cout<<solve2(1,0,0,cost);
}
int main(){
	IOS;
	solve();
	return 0;
}