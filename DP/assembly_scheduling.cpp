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
void solve(){
	read(n);
	int entry[2];
	int exit[2];
	cin>>entry[0]>>entry[1]>>exit[0]>>exit[1];
	int machine_time[2][n],shift_time[2][n];
	for(int j=0;j<2;j++){
	for(int i=0;i<n;i++){
       cin>>machine_time[j][i];		
	}
	}
	for(int j=0;j<2;j++){
	for(int i=0;i<n;i++){
       cin>>shift_time[j][i];		
	}
	}
	// int dp[n][2]; 
	int first,second;
	// dp[n-1][0]=machine_time[0][n-1]+exit[0];
	// dp[n-1][1]=machine_time[1][n-1]+exit[1];
	first=machine_time[0][n-1]+exit[0];
	second=machine_time[1][n-1]+exit[1];
	for(int i=n-2;i>=0;i--){
		// dp[i][0]=machine_time[0][i]+min(dp[i+1][0],shift_time[0][i+1]+dp[i+1][1]);
		// dp[i][1]=machine_time[1][i]+min(dp[i+1][1],shift_time[1][i+1]+dp[i+1][0]);
		first=machine_time[0][i]+min(first,shift_time[0][i+1]+second);
		second=machine_time[1][i]+min(second,shift_time[1][i+1]+first);
		
	}
	// cout<< min(dp[0][0]+entry[0],entry[1]+dp[0][1]);
	cout<< min(first+entry[0],entry[1]+second);
}
int main(){
	IOS;
	solve();
	return 0;
}