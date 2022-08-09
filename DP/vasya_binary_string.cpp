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
ll bestlen[102];
ll dp[102][102][102];
void init_code(){
	IOS;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
void rod_cutting(vector<ll>costs){
  int len=costs.size();
  bestlen[0]=0;
  for(int i=1;i<=len;i++){
  	for(int j=1;j<=i;j++){
  		bestlen[i]=max(bestlen[i],costs[j-1]+bestlen[i-j]);
  	}
  }
}
ll solve2(vector<int>& groups,int i,int j,int extra){
	if(i>j)return 0;
	if(dp[i][j][extra]!=-1)return dp[i][j][extra];
	ll answer=bestlen[groups[i]+extra]+solve2(groups,i+1,j,0);
	for(int group=i+2;group<=j;group+=2){
		answer=max(answer,solve2(groups,i+1,group-1,0)+solve2(groups,group,j,extra+groups[i]));
	}
	return dp[i][j][extra]=answer;
	
}
void solve(){
	read(n);
	string s;
	cin>>s;
	vector<ll>costs(n);
	rep(i,0,n){
		cin>>costs[i];
	}
	// for(auto z:costs){
	// 	cout<<z<<" ";
	// }
	// cout<<endl;
	fill(bestlen,0);
	fill(dp,-1);
	rod_cutting(costs);
	vector<int> groups;
	int count=0;
	int i=0;
	while(i<s.size()){
		if(i==0){
			count++;
		}
		else{
			if(s[i]==s[i-1]){
				count++;
			}
			else{
				groups.push_back(count);
				count=1;
			}
		}
		i++;
	}
	groups.push_back(count);
  cout<<solve2(groups,0,groups.size()-1,0);

}
int main(){
	IOS;
	solve();
	return 0;
}