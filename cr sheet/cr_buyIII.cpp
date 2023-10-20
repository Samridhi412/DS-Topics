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
long f(long* values,int n,int cap,int buy,int ind,vector<vector<vector<long>>>& dp){
	if(ind==n || cap==0){
		return 0;
	}
	if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
	if(buy){
		return dp[ind][buy][cap]=max(-values[ind]+f(values,n,cap,0,ind+1,dp),f(values,n,cap,1,ind+1,dp));
	}
	return dp[ind][buy][cap]=max(values[ind]+f(values,n,cap-1,1,ind+1,dp),f(values,n,cap,0,ind+1,dp));
}
long new_f(long* values,int n,int ind,int transaction_no,vector<vector<long>>& dp){
	if(ind==n ||transaction_no==4){
		return 0;
	}
	if(dp[ind][transaction_no]!=-1)return dp[ind][transaction_no];
	if(transaction_no%2==0){
		return dp[ind][transaction_no]=max(-values[ind]+new_f(values,n,ind+1,transaction_no+1,dp),new_f(values,n,ind+1,transaction_no,dp));
	}
	return dp[ind][transaction_no]=max(values[ind]+new_f(values,n,ind+1,transaction_no+1,dp),new_f(values,n,ind+1,transaction_no,dp));
}
void solve(){
	int n;
	cin>>n;
	long values[n];
	for(int i=0;i<n;i++){
		cin>>values[i];
	}
	vector<vector<vector<long>>> dp(n+1,vector<vector<long>>(2,vector<long>(3,-1)));
	// f(values,n,2,1,0,dp);
	// vector<vector<long>> dp2(n+1,vector<long>(5,-1));
	// cout<<new_f(values,n,0,0,dp2);
	// vector<vector<long>> dp2(n+1,vector<long>(5,0));
	vector<long> prev(5,0),curr(5,0);
	// for(int i=0;i<=4;i++){
	// 	dp2[n][i]=0;
	// }
	// for(int i=0;i<=n;i++){
	// 	dp2[i][4]=0;
	// }
	for(int i=n-1;i>=0;i--){
		for(int j=3;j>=0;j--){
			if(j%2==0){
				curr[j]=max(-values[i]+prev[j+1],prev[j]);
			}
			else{
				curr[j]=max(values[i]+prev[j+1],prev[j]);
			}
			prev=curr;
		}
	}
	// cout<<dp2[0][0];
	cout<<prev[0];
	// vector<vector<vector<long>>> dpp(n+1,vector<vector<long>>(2,vector<long>(3,0)));
	// vector<vector<long>> prev(2,vector<long>(3,0)),curr(2,vector<long>(3,0));
	// for(int i=0;i<=1;i++){
	// 	for(int j=0;j<=2;j++){
	// 		dpp[n][i][j]=0;
	// 	}
	// }
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=1;j++){
	// 		dpp[i][j][0]=0;
	// 	}
	// }
	//3,3,5,0,0,3,1,4
	// for(int i=n-1;i>=0;i--){
	// 	for(int j=0;j<=1;j++){
	// 		for(int k=1;k<=2;k++){
	// 			if(j){
	// 				curr[j][k]=max(-values[i]+prev[0][k],prev[1][k]);
	// 			}
	// 			else{
	// 			curr[j][k]=max(values[i]+prev[1][k-1],prev[0][k]);
	// 			}
	// 		}
	// 	}
	// 	prev=curr;
	// }
	// cout<<prev[1][2];
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}