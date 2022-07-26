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
#define mod 1000000007
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
ld pi=3.1415926535897932;
ll dp[100001][2][11];
ll dp2[100001][2];
ll power[100001];
bool done=0;
int pow10(int n){
	if(!done){
	power[0]=1;
	for(int i=1;i<=100000;i++){
		power[i]=(power[i-1]*10LL)%mod;
	}
	done=1;
}
	return power[n];
}
ll cnt(string& s,int n,int tight){
	if(!tight)return (pow(10,n)+0.1);
	if(n==0)return 1;
	if(dp2[n][tight]!=-1)return dp2[n][tight];
	ll ans=0;
	int ub=s[s.size()-n]-'0';
	for(int i=0;i<=ub;i++){
		ans=(ans+cnt(s,n-1,i==ub))%mod;
	}
	return dp2[n][tight]=ans%mod;
}
ll g(string& s,int n,int tight=1,int prev=10){
	if(n==0){
		return 0;
	}
	else if(dp[n][tight][prev]!=-1)return dp[n][tight][prev];
	int ub=tight?s[s.size()-n]-'0':9;
	ll ans=0;
	for(int i=0;i<=ub;i++){
		if(i!=prev){
			ll contri = (i * (1LL * pow10(n-1) * cnt(s, n - 1, tight & (i == ub)))) % mod;
            ans= (ans + contri) % mod;
		}
			ans=(ans+g(s,n-1,tight&&(i==ub),i))%mod;
	}
	dp[n][tight][prev]=ans%mod;
	return ans;
}
ll brute(string& s,int n){
    int prev=10;
    ll res=0;
    for(int i=0;i<n;i++){
        if(s[i]-'0'!=prev){
            res=(res+(s[i]-'0')*pow10(n-i-1))%mod;
        }
        prev=s[i]-'0';
    }
    return res%mod;
}
void solve(){
	read(nl);
	string l;
	cin>>l;
	read(nr);
	string r;
	cin>>r;
	fill(dp,-1);
	fill(dp2,-1);
	ll ans1=g(l,nl)%mod;
	fill(dp,-1);
	fill(dp2,-1);
	ll ans2=g(r,nr)%mod;
	cout<<(ans2+(mod-ans1)+brute(l,nl))%mod<<endl;
	
}
int main(){
	IOS;
	ll t;
	cin>>t;
	rep(i,1,t+1){
		solve();
	}
	return 0;
}