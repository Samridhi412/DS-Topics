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
double dp[(1<<19)];
double prob[20][20];
double pMove(int prev_bitmask,int j,int n){
	int k=__builtin_popcount(prev_bitmask);
	ll denominator=(k*(k-1))/2;
	double moveprobab=0;
	for(int f=0;f<n;f++){
		if((1<<f)&prev_bitmask)
			moveprobab+=prob[f][j];
	}
	return moveprobab/(1.0*den);
}
double fish(int bitmask,int n){
	 int alive=__builtin_popcount(bitmask); //no of setbits
	 if(alive==n){
	 	return 1;
	 }
	 //never compare double with integers directly as precision problems like dp[bitmask]!=-1
	 else if(dp[bitmask]>-0.9)return dp[bitmask];
	 double answer=0;
	 for(int f=0;f<n;f++){
	 	if(!bitmask&(1<<f)){
	 		double prev_day=fish(bitmask^(1<<f),n);
	 		int prev_bitmask=bitmask^(1<<f);
	 		answer+=prev_day*pMove(prev_bitmask,f,n);
	 	}
	 }
	 return dp[bitmask]=answer;
}
void solve(){
	int n;
	cin>>n;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>prob[i][j];
		}
	}
	for(int i=0;i<n;i++){
		cout<<fixed<<setprecision(10)<<fish((1<<i),n)<<endl;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}