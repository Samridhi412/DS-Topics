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
	int n,low,high;
	cin>>n>>low>>high;
	vector<vector<int>> dp(n,vector<int>(2,0));
	int numodds=(high-low+1)/2;
	if(low%2&&high%2)numodds++;
	int numevens=(high-low+1)-numodds;
	dp[n-1][0]=numevens;
	dp[n-1][1]=numodds;
	cout<<numodds<<" "<<numevens<<endl;
	for(int i=n-2;i>=0;i--){
		dp[i][0]=numevens*dp[i+1][0]+numodds*dp[i+1][1];
		dp[i][1]=numodds*dp[i+1][0]+numevens*dp[i+1][1];
	}
	cout<<dp[0][0];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}