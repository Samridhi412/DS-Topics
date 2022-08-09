#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
#define mp make_pair
#define pb push_back
#define endl "\n"
void solve(){
	ll n;
	cin>>n;
	if(n==0||n==1)cout<<1; return;
	// vector<int> dp(n+1);
	// dp[0]=1;
	// dp[1]=1;
	int a=1,b=1;
	int c;
	for(int i=2;i<=n;i++){
		// dp[i]=dp[i-1]+dp[i-2];
		c=b+a;
		a=b;
		b=c;
	}
	// cout<<dp[n];
	cout<<c<<endl;
}
void multiply(int F[2][2],int M[2][2]){
	int x=F[0][0]*M[0][0]+F[0][1]*M[1][0];
	int y=F[0][0]*M[0][1]+F[0][1]*M[1][1];
	int z=F[1][0]*M[0][0]+F[1][1]*M[1][0];
	int w=F[1][0]*M[0][1]+F[1][1]*M[1][1];
	F[0][0]=x;
	F][0][1]=y;
	F[1][0]=z;
	F[1][1]=w;
	
}
void power(int F[2][2],long long n){
	if(n==0||n==1){
		return;
	}
	power(F,n/2);
	multiply(F,F);
	int F[2][2]={{1,1},{1,0}};
	if(n%2){
		multiply(F,M);
	}
}
long long count_ways(long long n){
	if(n==0||n==1)return 1;
	int F[2][2]={{1,1},{1,0}};
	power(F,n-1);
	return F[0][0];
}
// n--->1e18 O(N) wont work---> matrix exponentiation--->O(logn)
void ME(long long n){
	
	cout<<count_ways(n);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}