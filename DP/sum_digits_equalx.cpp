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
ll dp[20][180][2];
ll optimal_digitdp(string& a,int n,int x,int tight=1){
	if(x<0)return 0;
	else if(n==1){
	  if(x>=0&&x<=9){
	  	return 1;
	  }
	  return 0;
	}
	else if(dp[n][x][tight]!=-1)return dp[n][x][tight];
	int ub=tight?a[a.size()-n]-'0':9;
	ll answer=0;
	for(int i=0;i<=ub;i++){
		answer+=optimal_digitdp(a,n-1,x-i,(tight&(i==ub)));
	}
	return dp[n][x][tight]=answer;
}
bool check(int num,int sum){
	int res=0;
	while(num!=0){
		res+=num%10;
		num/=10;
	}
	return res==sum;
}
ll brute_force(int l,int r,int x){
	int ans=0;
	for(int i=l;i<=r;i++){
		if(check(i,x)){
			ans++;
		}
	}
	return ans;
}
void solve(){
	read(l);
	read(r);
	string b=to_string(r);
	fill(dp,-1);
	cout<<brute_force(l,r,5)<<endl;
	fill(dp,-1);
	cout<<optimal_digitdp(b,b.size(),5);
}
int main(){
	IOS;
	solve();
	return 0;
}