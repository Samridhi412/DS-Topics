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
struct node{
	int index;
	int vl;
	int minsteps;
};
int min_jumps(vector<int>& arr,int n){
	vector<int> dp(n);
	dp[n-1]=0;
	for(int i=n-2;i>=0;i--){
		if(arr[i]==0){
			dp[i]=-1;
			continue;
		}
		int minsteps=1e5;
		for(int j=1;j<=arr[i]&&i+j<n;j++){
			if(dp[i+j]!=-1)minsteps=min(minsteps,dp[i+j]);
		}
		dp[i]=minsteps==1e5?-1:1+minsteps;
	}
	
	queue<pair<node,string>> q;
	q.push({{0,arr[0],dp[0]},"0->"});
	while(!q.empty()){
		node nn=q.front().first;
		int index=nn.index;
		int jumps=nn.minsteps;
		string s=q.front().second;
		q.pop();
		if(jumps==0){
			cout<<s<<endl;
		}
		for(int j=1;j<=nn.vl&&index+j<n;j++){
			if(dp[index+j]==jumps-1){
				q.push({{index+j,arr[index+j],dp[index+j]},s+to_string(index+j)+"->"});
			}
		}
	}
	return dp[0];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<min_jumps(arr,n);
	return 0;
}