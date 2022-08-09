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
int dp[10000][10000];
int max_path_sum(vector<vector<int>>& matrix,int i,int j,int m){
	if(i==0){
		return matrix[0][j];
	}
	else if(i<0||j<0||j>=m)return INT_MIN;
	else if(dp[i][j]!=-1)return dp[i][j];
	int op1=max_path_sum(matrix,i-1,j,m);
	int op2=max_path_sum(matrix,i-1,j-1,m);
	int op3=max_path_sum(matrix,i-1,j+1,m);
	return dp[i][j]=matrix[i][j]+max({op1,op2,op3});
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<int>> matrix(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matrix[i][j];
		}
	}
	int maxi=INT_MIN;
	vector<int> prev(m);
	for(int i=0;i<m;i++){
		prev[i]=matrix[0][i];
	}
	    for(int j=1;j<n;j++){
	    	vector<int> curr(m);
	    	for(int k=0;k<m;k++){
	    		curr[k]=matrix[j][k];
	    		int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
	    		if(j>0)op1=prev[k];
	    		if(j>0&&k>0)op2=prev[k-1];
	    		if(j>0&&k+1<m)op3=prev[k+1];
	    		curr[k]+=max({op1,op2,op3});
	    	}
	    	prev=curr;
	    }
	    for(int i=0;i<m;i++)maxi=max(maxi,prev[i]);
	cout<<maxi<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}