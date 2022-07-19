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
	int a,b;
	cin>>a>>b;
	int dp[a+1][b+1]={0};
	// memset(dp,INT_MAX,sizeof(dp));
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(i==j){
				dp[i][j]=0;
				continue;
			}
			int ans=1e9;
			for(int ii=1;ii<j;ii++)
			{ans=min(ans,1+dp[i][j-ii]+dp[i][ii]);}
		    for(int jj=1;jj<i;jj++)
			{ans=min(ans,1+dp[i-jj][j]+dp[jj][j]);}
		dp[i][j]=ans;
		}
	}
	cout<<dp[a][b];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}