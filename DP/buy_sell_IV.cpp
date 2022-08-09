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
ll recur(vector<int>& arr,int n,int ind,int isbuy,int id,vector<vector<vector<ll>>>& dp){
	if(id==0||ind==n)return 0;
	else if(dp[ind][isbuy][id]!=-1)return dp[ind][isbuy][id];
	ll profit=-1e9;
	if(isbuy){
		profit=max(-arr[ind]+recur(arr,n,ind+1,0,id,dp),recur(arr,n,ind+1,1,id,dp));
	}
	else{
		profit=max(arr[ind]+recur(arr,n,ind+1,1,id-1,dp),recur(arr,n,ind+1,0,id,dp));
	}
	return dp[ind][isbuy][id]=profit;
}
ll space_op(vector<int>& arr,int n,int ind,int id,int k){
	if(ind==n||id==2*k)return 0;
	ll profit=-1e9;
	if(id%2==0){
		profit=max(-arr[ind]+space_op(arr,n,ind+1,id+1,k),space_op(arr,n,ind+1,id,k));
	}
	else{
		profit=max(arr[ind]+space_op(arr,n,ind+1,id+1,k),space_op(arr,n,ind+1,id,k));
	}
	return profit;
	
}
// ll space_op__dp(vector<int>& arr,int n,int k){
// 	vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
// 	for(int i=n-1;i>=0;i--){
// 		for(int id=2*k-1;id>=0;id--){
// 			if(!(id&1)){
// 				dp[i][id]=max(-arr[i]+dp[i+1][id+1],dp[i+1][id]);
// 			}
// 			else{
// 				dp[i][id]=max(arr[i]+dp[i+1][id+1],dp[i+1][id]);
// 			}
// 		}
// 	}
// 	// cout<<dp[0][0];
// 	return dp[0][0];
// }
ll space_op__dp(vector<int>& arr,int n,int k){
	vector<int> curr(2*k+1,0),after(2*k+1,0);
	for(int i=n-1;i>=0;i--){
		for(int id=2*k-1;id>=0;id--){
			if(!(id&1)){
				curr[id]=max(-arr[i]+after[id+1],after[id]);
			}
			else{
				curr[id]=max(arr[i]+after[id+1],after[id]);
			}
		}
after=curr;
	}
	return after[0];
}
void solve(){
	ll n;
	cin>>n;
	int k;
		cin>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	vector<vector<vector<ll>>> dpp(n,vector<vector<ll>>(2,vector<ll>(k+1,-1)));

	cout<<recur(arr,n,0,1,k,dpp)<<endl;
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
	for(int i=n-1;i>=0;i--){
		for(int id=1;id<=k;id++){
			dp[i][1][id]=max(-arr[i]+dp[i+1][0][id],dp[i+1][1][id]);
			dp[i][0][id]=max(arr[i]+dp[i+1][1][id+1],dp[i+1][0][id]);
		}
	}
	cout<<dp[0][1][k]<<endl;
	cout<<space_op(arr,n,0,0,k)<<endl;
	cout<<space_op__dp(arr,n,k);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}