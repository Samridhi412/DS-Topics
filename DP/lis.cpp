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
int lis(vector<int>& arr,int ind,int prev,vector<vector<int>>& dp){
	if(ind==arr.size()){
		return 0;
	}
	else if(dp[ind][prev]!=-1)return dp[ind][prev+1];
	int nontake=lis(arr,ind+1,prev,dp);
	int take=0;
	if(prev==-1||arr[ind]>arr[prev+1]){
		take=1+lis(arr,ind+1,ind,dp);
	}
	return dp[ind][prev+1]= max(take,nontake);
}
void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<vector<int>> dpp(n+1,vector<int>(n+1,-1));
	cout<<lis(arr,0,-1,dpp);
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	vector<int> curr(n+1,0),next(n+1,0);
	for(int i=n-1;i>=0;i--){
		for(int j=i-1;j>=-1;j--){
			int nontake=dp[i+1][j+1];
				// int nontake=next[j+1];
			int take=0;
			if(j==-1||arr[i]>arr[j]){
				take=1+dp[i+1][i];
				// take=1+next[i];
			}
			// dp[i][j+1]= max(take,nontake);
			curr[j+1]=max(take,nontake);
		}
		// next=curr;
	}
	cout<<dp[0][0];
	// cout<<next[0];
}
void lis(vector<int>& arr,int n){
	vector<int> hash(n),dp(n);
	int lastindex=-1;
	int maxi=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
				hash[i]=j;
			}
		}
		if(dp[i]>maxi){
			maxi=dp[i];
			lastindex=i;
		}
	}
	int temp[maxi];
	int ind=maxi-1;
	while(hash[lastindex]!=lastindex){
		temp[ind]=arr[lastindex];
		lastindex=hash[lastindex];
		ind--;
	}
	for(auto x:temp){
		cout<<x<<" ";
	}
	
}
void binary_search(vector<int>& arr,int n){
	vector<int> temp;
	temp.push_back(arr[0]);
	for(int i=1;i<n;i++){
		if(temp.back()<arr[i]){
			temp.push_back(arr[i]);
		}
		else{
			int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
			temp[ind]=arr[i];
		}
	}
	cout<<temp.size();
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}